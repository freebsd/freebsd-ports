src/libavoid/connector.cpp:888:29: error: call to 'abs' is ambiguous
                COLA_ASSERT(abs((long)i->pathNext->id.objID - i->id.objID) != 2);
                            ^~~
src/libavoid/assertions.h:41:39: note: expanded from macro 'COLA_ASSERT'
    #define COLA_ASSERT(expr)  assert(expr)
                                      ^~~~
/usr/include/assert.h:56:21: note: expanded from macro 'assert'
#define assert(e)       ((e) ? (void)0 : __assert(__func__, __FILE__, \
                          ^
/usr/include/c++/v1/math.h:733:1: note: candidate function
abs(float __lcpp_x) _NOEXCEPT {return ::fabsf(__lcpp_x);}
^
/usr/include/c++/v1/math.h:737:1: note: candidate function
abs(double __lcpp_x) _NOEXCEPT {return ::fabs(__lcpp_x);}
^
/usr/include/c++/v1/math.h:741:1: note: candidate function
abs(long double __lcpp_x) _NOEXCEPT {return ::fabsl(__lcpp_x);}
^
/usr/include/stdlib.h:87:6: note: candidate function
int      abs(int) __pure2;
         ^
/usr/include/c++/v1/stdlib.h:111:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long      abs(     long __x) _NOEXCEPT {return  labs(__x);}
                                           ^
/usr/include/c++/v1/stdlib.h:113:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long long abs(long long __x) _NOEXCEPT {return llabs(__x);}
                                           ^

--- src/libavoid/connector.cpp.orig	2018-03-11 20:38:09 UTC
+++ src/libavoid/connector.cpp
@@ -885,7 +885,7 @@ bool ConnRef::generatePath(void)
             {
                 // Check for consecutive points on opposite 
                 // corners of two touching shapes.
-                COLA_ASSERT(abs((long)i->pathNext->id.objID - i->id.objID) != 2);
+                COLA_ASSERT(abs((long)(i->pathNext->id.objID - i->id.objID)) != 2);
             }
         }
     }
