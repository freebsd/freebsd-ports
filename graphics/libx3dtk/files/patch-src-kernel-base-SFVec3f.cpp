*** src/kernel/base/SFVec3f.cpp.orig	Thu Sep 28 13:02:11 2006
--- src/kernel/base/SFVec3f.cpp	Thu Sep 28 13:02:37 2006
***************
*** 69,85 ****
  
  // operations on vectors
  //overloading of the operators +, -, *
! bool X3DTK::operator== (const SFVec3f &v1, const SFVec3f &v2)
  {
    return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
  }
  
! bool X3DTK::operator!= (const SFVec3f &v1, const SFVec3f &v2)
  {
    return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z));
  }
  
! SFVec3f X3DTK::operator+ (const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.x + v2.x;
--- 69,85 ----
  
  // operations on vectors
  //overloading of the operators +, -, *
! bool operator== (const SFVec3f &v1, const SFVec3f &v2)
  {
    return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
  }
  
! bool operator!= (const SFVec3f &v1, const SFVec3f &v2)
  {
    return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z));
  }
  
! SFVec3f operator+ (const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.x + v2.x;
***************
*** 88,94 ****
    return res;
  }
  
! SFVec3f X3DTK::operator- (const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.x - v2.x;
--- 88,94 ----
    return res;
  }
  
! SFVec3f operator- (const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.x - v2.x;
***************
*** 97,103 ****
    return res;
  }
  
! SFVec3f X3DTK::operator- (const SFVec3f &v)
  {
    SFVec3f res;
    res.x = -v.x;
--- 97,103 ----
    return res;
  }
  
! SFVec3f operator- (const SFVec3f &v)
  {
    SFVec3f res;
    res.x = -v.x;
***************
*** 107,118 ****
  }
  
  //scalar product
! float X3DTK::operator* (const SFVec3f &v1, const SFVec3f &v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }
  
! SFVec3f X3DTK::operator* (const float a, const SFVec3f &v)
  {
    SFVec3f res;
    res.x = a * v.x;
--- 107,118 ----
  }
  
  //scalar product
! float operator* (const SFVec3f &v1, const SFVec3f &v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }
  
! SFVec3f operator* (const float a, const SFVec3f &v)
  {
    SFVec3f res;
    res.x = a * v.x;
***************
*** 122,128 ****
  }
  
  //crossproduct 
! SFVec3f X3DTK::crossprod(const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.y * v2.z - v1.z * v2.y;
--- 122,128 ----
  }
  
  //crossproduct 
! SFVec3f crossprod(const SFVec3f &v1, const SFVec3f &v2)
  {
    SFVec3f res;
    res.x = v1.y * v2.z - v1.z * v2.y;
