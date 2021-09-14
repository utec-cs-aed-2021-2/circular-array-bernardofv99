#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <deque>
#include <chrono>
#include <fstream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:

    CircularArray();

    CircularArray(int _capacity);
    
    virtual ~CircularArray();

    void push_front(T data);
    
    void push_back(T data);   
    
    void insert(T data, int pos);
    
    T pop_front();

    T pop_back();

    bool is_full(){
        return next(back) == front;
    }
    
    bool is_empty(){
        return (front == -1);
    }

    int size(){
        if (front == back){
            return 1;
        }
        else if (front > back){
            return capacity - (front - back) - 1;
        } 
        else if (back > front){
            return (front - back) + 1;
        }
        return 0;
    }
    
    void clear();
    
    T &operator[](int pos);
    
    bool is_sorted(){
        for (int i = front; i = back; next(i)){
            if (array[i] <= array[next(i)]){
                return true;
            }
            return false;
        }
    }
    
    void sort();

    void reverse(){
        int inicio= front,final = back;
        for(int q=0;q<size()/2;q++){
            swap(array[inicio],array[final]);
            inicio = next(inicio);
            final = prev(final);
        }
    };
    
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
    void quicksort(int mini, int maxi);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template<class T>
T &CircularArray<T>::operator[](int pos) {
    return array[pos];
}

template<class T>
T CircularArray<T>::pop_back() {
    if(is_empty()){
            cout << "No hay nada para eliminar";
    }
    else if (front == back) {
        front = -1; back = -1;             
    }
    else {
        array[back] = -1;
        if (back == 0){
            back = 6;
        }
        else{
            back = prev(back);
        }
    }
}

template<class T>
T CircularArray<T>::pop_front() {
    if(is_empty()){
        cout << "No hay nada para eliminar";
    }
    else if (front == back) {
        front = -1; back = -1;             
    }
    else {
        array[front] = -1;
        if (front == 6){
            front = 0;
        }
        else{
            front = next(front);
        }
    }
}


template<class T>
void CircularArray<T>::push_front(T data) {
    if(is_empty()){
        front = 0;
        back = 0;
        array[0] = data;
    }
    else if (is_full()) {
        cout << "Array lleno";
    }
    else{
        if (front == 7) {
            front = 0;
        }
        else{
            front = prev(front);  
        }                  
        array[front] = data;
    } 
}

template<class T>
void CircularArray<T>::push_back(T data) {
    if(is_empty()){
        front = 0;
        back = 0;
    }
    else if (is_full()) {
        cout << "Array lleno";
    }
    else{
        if (back == capacity - 1){
            back = 0;
        }
        else
            back = next(back);
        array[back] = data;          
    }
    array[back] = data;  
}

template<class T>
void CircularArray<T>::quicksort(int mini, int maxi){
    int y, z, pivote, aux, start=0;
    y = mini;
    z = maxi;

    pivote = array[(mini + maxi) / 2 ];
    do{
        while((array[y] < pivote) && (z <= maxi) ){
            y++;
        }
        while((pivote < array[z]) && (z > mini) ){
            z--;
        }
        if(y <= z ){
            aux = array[y];
            array[y] = array[z];
            array[z] = aux;
            y++;
            z--;
        }
    }while(y <= z);

    if(mini < z ){
        quicksort(mini, z );
    }
    if(y < maxi ){
        quicksort(y, maxi);
    }    
}

template<class T>
void CircularArray<T>::sort() {
    quicksort(0, capacity-1);
}

