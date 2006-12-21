*** src/kernel/base/SFPoint2f.cpp.orig	Sun Dec 17 12:28:27 2006
--- src/kernel/base/SFPoint2f.cpp	Sun Dec 17 12:30:01 2006
***************
*** 67,74 ****
  
  // operations on points
  //overloading of the operators +, -, *
  
! SFPoint2f X3DTK::operator+ (const SFPoint2f &v1, const SFVec2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x + v2.x;
--- 67,75 ----
  
  // operations on points
  //overloading of the operators +, -, *
+ namespace X3DTK {
  
! SFPoint2f operator+ (const SFPoint2f &v1, const SFVec2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x + v2.x;
***************
*** 76,82 ****
    return res;
  }
  
! SFPoint2f X3DTK::operator+ (const SFPoint2f &v1, const SFPoint2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x + v2.x;
--- 77,83 ----
    return res;
  }
  
! SFPoint2f operator+ (const SFPoint2f &v1, const SFPoint2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x + v2.x;
***************
*** 84,90 ****
    return res;
  }
  
! SFPoint2f X3DTK::operator- (const SFPoint2f &v1, const SFVec2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x - v2.x;
--- 85,91 ----
    return res;
  }
  
! SFPoint2f operator- (const SFPoint2f &v1, const SFVec2f &v2)
  {
    SFPoint2f res;
    res.x = v1.x - v2.x;
***************
*** 92,98 ****
    return res;
  }
  
! SFVec2f X3DTK::operator- (const SFPoint2f &v1, const SFPoint2f &v2)
  {
    SFVec2f res;
    res.x = v1.x - v2.x;
--- 93,99 ----
    return res;
  }
  
! SFVec2f operator- (const SFPoint2f &v1, const SFPoint2f &v2)
  {
    SFVec2f res;
    res.x = v1.x - v2.x;
***************
*** 100,106 ****
    return res;
  }
  
! SFPoint2f X3DTK::operator* (const float a, const SFPoint2f &v)
  {
    SFPoint2f res;
    res.x = a * v.x;
--- 101,107 ----
    return res;
  }
  
! SFPoint2f operator* (const float a, const SFPoint2f &v)
  {
    SFPoint2f res;
    res.x = a * v.x;
***************
*** 108,115 ****
    return res;
  }
  
! float X3DTK::distance(const SFPoint2f &A, const SFPoint2f &B)
  {
    return (A - B).norm();
  }
  
--- 109,117 ----
    return res;
  }
  
! float distance(const SFPoint2f &A, const SFPoint2f &B)
  {
    return (A - B).norm();
  }
  
+ }
