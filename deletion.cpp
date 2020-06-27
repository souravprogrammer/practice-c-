#include<iostream>
class array
{
    int *arr ;
    int siz ;
    void sort()
    {
        int temp ;
        for(int i=0;i<siz;i++)
        {
            for(int j=0 ;j<siz-i;j++)
            {
                if(arr[j]>arr[j+1]){
                temp =arr[j];
                arr[i+1]= arr[i];
                arr[i]=temp;
                }
            }
        }
    }
public:
   int &operator[](int idx)
    {
        if(idx<siz && idx>=0)
        {
        return arr[idx] ;
        }else{std::cout<<"ERROR :: 'out of array range' "<<std::endl;}
    }
    array()
    {}
    array(int size)
    {
        arr = new int[size];
        siz = size ;
    }
    void remove(int index)
    {
        int *buffer = new int[siz];
        for(int i=0;i<siz;i++)
        {
            buffer[i]=arr[i];
        }
        delete[] arr ;
        siz = siz-1;
        arr = new int[siz];

        for(int i=0,x =0;i<siz;x++,i++)
        {
            if(i<index){
            arr[i] = buffer[i];}else if(i>=index)
            {
                arr[i] =buffer[i+1];
            }
        }
    }

    void fill(int start,int end ,int eliment)
    {
        for(int i=start;i<=end;i++)
        {
            arr[i]=eliment;
        }
    }
    void print(int start = 0,int end = 0)
    {
        if(end==0)
        end =siz;
        for(int i=start;i<end;i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
    ~array()
    {
        delete[] arr ;
    }
    int begin()
    {
        return 0;
    }
    int end()
    {
        return siz;
    }
    int search(const int &eliment,int start =0,int end=0 )
    {
        if(end ==0)
        end = siz;
        for(int i =start ;i<=end ;i++)
        {
            if(arr[i]==eliment)
            {
                return i ;
            }
        }
        return -1;
    }

    };
int main()
{

    return 0 ;
}
