#include<iostream>
using namespace std;
template<typename T>
class vector
{
public:
   enum{cap = 5 };
   typedef T* iterator;
   typedef const T* const_iterator;

   explicit vector(int initsize = 0);
   vector(int initsize, T value);
   vector(iterator b, iterator e);
   vector(std::initializer_list<T> l);

   vector(const vector &rhs);
   vector<T>& operator=(const vector & rhs);
   ~vector() { delete[] elem;}



    bool empty()const  { return thesize == 0;}
    int size() const   {return thesize;}
    int capacity() const { return thecapacity; }

    bool operator==(const vector<T>& rhs);
    bool operator!=(const vector<T>& rhs);


    void reserve(int newcapacity);
    void resize(int newsize, const T &thevalue);
    void resize(int newsize);
    void shrink_to_fit();

    T &operator[](int index);
    const T &operator[](int index) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    void push_back(const T &x);
    iterator insert(iterator b, const T &value);
    void pop_back() {thesize--;}
    iterator erase(iterator b);
    void clear();
 iterator begin()  {return &elem[0];}
    iterator end()  {return &elem[thesize];}
    const_iterator cbegin()const {return &elem[0];}
    const_iterator cend() const {return &elem[thesize];}

private:
    T *elem;
    int thesize;
    int thecapacity;
};
template <typename T>
vector<T>::vector(int initsize = 0) :thesize(initsize), thecapacity(initsize +cap)
{
    elem = new T[thecapacity];
    assert(elem != NULL);
}
