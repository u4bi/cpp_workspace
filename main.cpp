#include <iostream> 
#include <cstring>
 
/*  참조자를 사용해서 Call by reference(참조에 의한 호출)이 가능함

    a와 b의 값을 서로 바꾸는 swap함수를 참조자를 이용해 작성해보기
*/

#define PI 3.141592
// #define CU(x) ((x)*(x)*(x))

inline int CU(int x){
    return x*x*x;
}

namespace A { void Add() { printf("A의 Add() 호출 \n");}}
namespace B { void Add() { printf("B의 Add() 호출 \n");}}

namespace u4bi{ void good(){ printf("u4bi c++ \n"); } }
namespace github{
    void win(){ printf("github win\n");}
    void lose(){ printf("github lose\n");}
}

using namespace u4bi;
using github::win;

using namespace std;

class deep{
private:
    char *str;
public:
    deep(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    deep(const deep& dp){
        str = new char[strlen(dp.str)+1];
        strcpy(str, dp.str);
    }
    ~deep(){
        delete []str;
        cout << "~deep()" << endl;
    }
    void show(){
        cout << "str : " << str << endl;
    }
};

class shallow{
private:
    char *str;
public:
    shallow(const char *_str){
        str = new char[strlen(_str)+1];
        strcpy(str, _str);
    }
    ~shallow(){
        delete []str;
        cout << "~shallow()" << endl;
    }
    void show(){
        cout << "str: " << str << endl;        
    }
};

class dog{
public:
    dog(){
        cout << "dog()" << endl;
    }
    ~dog(){
        cout << "~dog()" << endl;
    }
};

class copied{
private:
    int num1;
    int num2;
public:
    copied(int a, int b){
        num1 = a;
        num2 = b;
    }
    void show(){
        cout << "num1 : " << num1 << " num2 : " << num2 << endl;
    }
};

class human{
private:
    char *name;
    int age;
public:
    human();
    human(char *_name);
    human(char *_name, int age);
    void ShowInfo();
};
human::human(char *_name, int _age){
    name = _name;
    age = _age;
}
human::human(char *_name){
    cout << "human(char name) overloading" << endl;
}
human::human(){
    cout << "human() overloading" << endl;
}
void human::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << endl;
}

class child{
private:
    char *name;
    int age;
    char *hobby;
public:
    void ShowInfo();
    void SetInfo(char *_name, int _age, char *_hobby);
    void Study();
    void Sleep();
};
void child::ShowInfo(){
    cout << "이름 : " << name << " 나이 : " << age << " 취미 : " << hobby << endl;
}
void child::SetInfo(char *_name, int _age, char *_hobby){
    name = _name;
    age = _age;
    hobby = _hobby;
}
void child::Study(){
    cout << "공부!" << endl;
}
void child::Sleep(){
    cout << "잠!" << endl;
}

struct user{
private:
    int id;
    char *name;
    float exp;
public:
    void show();
    void setInfo(int _id, char * _name, float _exp);
};

void user::show(){
    cout << "번호 : " << id << endl;
    cout << "이름 : " << name << endl;
    cout << "경험 : " << exp << endl;
}

void user::setInfo(int _id, char * _name, float _exp){
    id = _id;
    name = _name;
    exp = _exp;
}

struct player{
    int id;
    char name[24];
    float exp;
    
    void show(){
        cout << "번호 : " <<id << endl;
        cout << "이름 : " <<name << endl;
        cout << "경험 : " <<exp << endl;
    }
    void show_Example2();
};

void player::show_Example2(){
    cout << "번호 : " <<id << endl;
    cout << "이름 : " <<name << endl;
    cout << "경험 : " <<exp << endl;
}

void func(int a){ cout << "int a : " << a << endl; }
void func(int a, int b){ cout << "int a : " << a << " int b : " << b << endl; }

void NewDeleteExample(){
    int len, total=0; int * score; int i;    
    cout << "학생수 입력 : ";
    cin >> len;
    
    score = new int[len];
    
    for(i=0; i<len; i++){
        cout << i+1 << "번 학생의 점수: ";
        cin >> score[i];
        total += score[i];
    }
    cout << "모든 학생의 평균: " << total/len << endl;
    delete []score;
}

void boolNum(){
    cout << true << endl;
    cout << false << endl;
}

void boolLen(){
    cout << "sizeof true: " << sizeof true << endl;
    cout << "sizeof false: " << sizeof false << endl;
}

void boolExample(){
    int a, b;
    bool isMax;
    
    cin >> a >> b;
    
    if(a>b) isMax = true;
    else isMax = false;
    
    cout << "isMax : " << isMax << endl;
}

void inlineExample(){
    cout << PI << endl;
    cout << CU(7.4) << endl;
}

void referenceExample(){
    int aaa=50;
    int &bbb=aaa;
    
    cout << "aaa : " << aaa << endl;
    cout << "bbb : " << bbb << endl;
    
    cout << "aaa path : " << &aaa << endl;
    cout << "bbb path : " << &bbb << endl;
}

void swap(int &ref_a, int &ref_b){
    /* 매개변수에 참조자를 위치함 */
    int temp = ref_a;
    
    ref_a = ref_b;
    ref_b = temp;
    /* 우선 넘겨주기 */
}
void callByReferenceExample(){
    
    int a = 50, b = 40;
    cout << "swap 하기전 a : " << a << " b : " << b << endl;
    /*  당연히 기존의 a와 b의 값을 출력 */
    
    swap(a, b);
    /*  swap 함수를 호출 그러면 a와 b가 swap 함수로 넘어감
    
        이렇게 넘어오면 참조자로 설정된 ref_a와 ref_b가 초기화
        ref_a는 넘어온 a를 가르키고 ref_b는 넘어온 b를 가르킴
        
        함수 내에서
        temp 변수에 ref_a(a)값을 넣어두고
        ref_a 변수에 ref_b(b)값을 넣어
        
        두 값이 서로 바뀜
    */
    cout << "swap 한 후 a : " << a << " b : " << b << endl;
    /*  참조자(레퍼런스)에 의해 바뀐 a와 b를 확인 */
}

int main() {

    callByReferenceExample();
    referenceExample();
    inlineExample();
    
    boolNum();
    boolLen();
    boolExample();

    deep dp1("deep copy");
    deep dp2 = dp1;
    dp1.show();
    dp2.show();
    
    /* deep copy test comment line
    shallow sw1("shallow copy");
    shallow sw2 = sw1;
    sw1.show();
    sw2.show();
	*/
    
    dog d;

    copied cp1(30, 31);
    copied cp2 = cp1;
    cp2.show();
    
    human h("u4bi", 12);
    h.ShowInfo();
    
    child c;
    c.SetInfo("u4bi", 11, "c++");
    c.ShowInfo();
    c.Study();
    c.Sleep();
    
    user u;
    u.setInfo(123, "u4bi", 55.6);
    u.show();
    
    player p = {1, "u4bi", 67.5};
    cout << "번호 : " <<p.id << endl;
    cout << "이름 : " <<p.name << endl;
    cout << "경험 : " <<p.exp << endl;
    
    p.show();
    p.show_Example2();
    
    int * ptr1 = new int;
    int * ptr2 = new int[10];
    delete ptr1;
    delete []ptr2;
    
    func(4);
    func(5, 6);
    
    good();
    
    win();
    github::lose();
    
    A::Add();
    B::Add();

    NewDeleteExample();

    char name[10];
    int age;
    std::cin>>name>>age;
    std::cout << "내 닉네임은 " << name << "이며 " << age << "살입니다." <<std::endl;
    std::cout << "u4bi c++ workspace" <<std::endl;
    return 0;
}