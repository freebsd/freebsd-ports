*** src/kernel/base/SFVec2f.cpp.orig	Sun Dec 17 12:38:08 2006
--- src/kernel/base/SFVec2f.cpp	Sun Dec 17 12:38:57 2006
***************
*** 60,78 ****
    y = P.y;
  }
  
  // operations on vectors
  //overloading of the operators +, -, *
! bool X3DTK::operator== (const SFVec2f &v1, const SFVec2f &v2)
  {
    return ((v1.x == v2.x) && (v1.y == v2.y));
  }
  
! bool X3DTK::operator!= (const SFVec2f &v1, const SFVec2f &v2)
  {
    return ((v1.x != v2.x) || (v1.y != v2.y));
  }
  
! SFVec2f X3DTK::operator+ (const SFVec2f &v1, const SFVec2f &v2)
  {
    SFVec2f res;
    res.x = v1.x + v2.x;
--- 60,79 ----
    y = P.y;
  }
  
+ namespace X3DTK {
  // operations on vectors
  //overloading of the operators +, -, *
! bool operator== (const SFVec2f &v1, const SFVec2f &v2)
  {
    return ((v1.x == v2.x) && (v1.y == v2.y));
  }
  
! bool operator!= (const SFVec2f &v1, const SFVec2f &v2)
  {
    return ((v1.x != v2.x) || (v1.y != v2.y));
  }
  
! SFVec2f operator+ (const SFVec2f &v1, const SFVec2f &v2)
  {
    SFVec2f res;
    res.x = v1.x + v2.x;
***************
*** 80,86 ****
    return res;
  }
  
! SFVec2f X3DTK::operator- (const SFVec2f &v1, const SFVec2f &v2)
  {
    SFVec2f res;
    res.x = v1.x - v2.x;
--- 81,87 ----
    return res;
  }
  
! SFVec2f operator- (const SFVec2f &v1, const SFVec2f &v2)
  {
    SFVec2f res;
    res.x = v1.x - v2.x;
***************
*** 88,94 ****
    return res;
  }
  
! SFVec2f X3DTK::operator- (const SFVec2f &v)
  {
    SFVec2f res;
    res.x = -v.x;
--- 89,95 ----
    return res;
  }
  
! SFVec2f operator- (const SFVec2f &v)
  {
    SFVec2f res;
    res.x = -v.x;
***************
*** 97,113 ****
  }
  
  //scalar product
! float X3DTK::operator* (const SFVec2f &v1, const SFVec2f &v2)
  {
    return v1.x * v2.x + v1.y * v2.y;
  }
  
! SFVec2f X3DTK::operator* (const float a, const SFVec2f &v)
  {
    SFVec2f res;
    res.x = a * v.x;
    res.y = a * v.y;
    return res;
  }
  
  //norm2 
--- 98,115 ----
  }
  
  //scalar product
! float operator* (const SFVec2f &v1, const SFVec2f &v2)
  {
    return v1.x * v2.x + v1.y * v2.y;
  }
  
! SFVec2f operator* (const float a, const SFVec2f &v)
  {
    SFVec2f res;
    res.x = a * v.x;
    res.y = a * v.y;
    return res;
+ }
  }
  
  //norm2 
