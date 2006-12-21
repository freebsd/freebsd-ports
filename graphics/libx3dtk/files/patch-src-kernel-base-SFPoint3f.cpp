*** src/kernel/base/SFPoint3f.cpp.orig	Sun Dec 17 12:30:22 2006
--- src/kernel/base/SFPoint3f.cpp	Sun Dec 17 12:31:00 2006
***************
*** 75,81 ****
  // operations on points
  //overloading of the operators +, -, *
  
! SFPoint3f X3DTK::operator+ (const SFPoint3f &v1, const SFVec3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x + v2.x;
--- 75,82 ----
  // operations on points
  //overloading of the operators +, -, *
  
! namespace X3DTK {
! SFPoint3f operator+ (const SFPoint3f &v1, const SFVec3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x + v2.x;
***************
*** 84,90 ****
    return res;
  }
  
! SFPoint3f X3DTK::operator+ (const SFPoint3f &v1, const SFPoint3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x + v2.x;
--- 85,91 ----
    return res;
  }
  
! SFPoint3f operator+ (const SFPoint3f &v1, const SFPoint3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x + v2.x;
***************
*** 93,99 ****
    return res;
  }
  
! SFPoint3f X3DTK::operator- (const SFPoint3f &v1, const SFVec3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x - v2.x;
--- 94,100 ----
    return res;
  }
  
! SFPoint3f operator- (const SFPoint3f &v1, const SFVec3f &v2)
  {
    SFPoint3f res;
    res.x = v1.x - v2.x;
***************
*** 102,108 ****
    return res;
  }
  
! SFVec3f X3DTK::operator- (const SFPoint3f &v1, const SFPoint3f &v2)
  {
    SFVec3f res;
    res.x = v1.x - v2.x;
--- 103,109 ----
    return res;
  }
  
! SFVec3f operator- (const SFPoint3f &v1, const SFPoint3f &v2)
  {
    SFVec3f res;
    res.x = v1.x - v2.x;
***************
*** 111,117 ****
    return res;
  }
  
! SFPoint3f X3DTK::operator* (const float a, const SFPoint3f &v)
  {
    SFPoint3f res;
    res.x = a * v.x;
--- 112,118 ----
    return res;
  }
  
! SFPoint3f operator* (const float a, const SFPoint3f &v)
  {
    SFPoint3f res;
    res.x = a * v.x;
***************
*** 120,127 ****
    return res;
  }
  
! float X3DTK::distance(const SFPoint3f &A, const SFPoint3f &B)
  {
    return (A - B).norm();
  }
! 
--- 121,128 ----
    return res;
  }
  
! float distance(const SFPoint3f &A, const SFPoint3f &B)
  {
    return (A - B).norm();
  }
! }
