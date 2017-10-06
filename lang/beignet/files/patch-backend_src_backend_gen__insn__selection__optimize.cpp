backend/src/backend/gen_insn_selection_optimize.cpp:462:22: error: call to 'abs' is ambiguous
                s0 = abs(s0);
                     ^~~
/usr/include/stdlib.h:85:6: note: candidate function
int      abs(int) __pure2;
         ^
/usr/include/c++/v1/stdlib.h:115:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long      abs(     long __x) _NOEXCEPT {return  labs(__x);}
                                           ^
/usr/include/c++/v1/stdlib.h:117:44: note: candidate function
inline _LIBCPP_INLINE_VISIBILITY long long abs(long long __x) _NOEXCEPT {return llabs(__x);}
                                           ^
/usr/include/c++/v1/math.h:640:1: note: candidate function
abs(float __lcpp_x) _NOEXCEPT {return fabsf(__lcpp_x);}
^
/usr/include/c++/v1/math.h:644:1: note: candidate function
abs(double __lcpp_x) _NOEXCEPT {return fabs(__lcpp_x);}
^
/usr/include/c++/v1/math.h:648:1: note: candidate function
abs(long double __lcpp_x) _NOEXCEPT {return fabsl(__lcpp_x);}
^

--- backend/src/backend/gen_insn_selection_optimize.cpp.orig	2017-06-23 08:05:54 UTC
+++ backend/src/backend/gen_insn_selection_optimize.cpp
@@ -459,13 +459,13 @@ namespace gbe
             {
               unsigned int s0 = src0.value.ud;
               if (src0.absolute)
-                s0 = abs(s0);
+                s0 = s0;
               if (src0.negation)
                 s0 = -s0;
 
               unsigned int s1 = src1.value.ud;
               if (src1.absolute)
-                s1 = abs(s1);
+                s1 = s1;
               if (src1.negation)
                 s1 = -s1;
 
