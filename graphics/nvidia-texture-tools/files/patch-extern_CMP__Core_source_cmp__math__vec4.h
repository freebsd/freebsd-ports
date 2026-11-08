--- extern/CMP_Core/source/cmp_math_vec4.h.orig	2020-08-24 06:27:21 UTC
+++ extern/CMP_Core/source/cmp_math_vec4.h
@@ -322,10 +322,12 @@ class Vec4 (public)
 };
 
 #include <stdio.h>
-#include "xmmintrin.h"
 #include <math.h>
 #include <float.h> 
 
+#if defined(__i386__) || defined(__x86_64__) || defined(_M_IX86) || defined(_M_X64)
+#include "xmmintrin.h"
+
 // SSE Vec4
 #ifdef _LINUX
 class CMP_SSEVec4f
@@ -419,6 +421,8 @@ class   __declspec(align(16)) CMP_SSEVec4f (public)
     };
 
 };
+
+#endif
 
 typedef Vec4<float>             CMP_Vec4f;
 typedef Vec4<double>            CMP_Vec4d;
