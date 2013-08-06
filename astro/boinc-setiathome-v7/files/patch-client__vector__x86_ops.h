--- client/vector/x86_ops.h.orig	2011-05-22 21:08:50.000000000 +0200
+++ client/vector/x86_ops.h	2013-07-29 17:42:54.000000000 +0200
@@ -135,7 +135,11 @@
 
 #if defined(__SSE2__)
 // SSE2 specific functions/macros here.
-#ifdef _MSC_VER
+#ifdef __clang__
+#ifndef __EMMINTRIN_H
+#include <emmintrin.h>
+#endif
+#elif defined _MSC_VER
 typedef __m128d x86_m128d;
 #else
 typedef double x86_m128d __attribute__ ((mode(V2DF))) __attribute__((aligned(16)));
@@ -144,7 +148,11 @@
 
 #if defined(__SSE__)
 // SSE specific functions/macros here.
-#ifdef _MSC_VER
+#ifdef __clang__
+#ifndef __XMMINTRIN_H
+#include <xmmintrin.h>
+#endif
+#elif defined _MSC_VER
 typedef __m128 x86_m128;
 typedef __m128i x86_m128i;
 #else
@@ -186,6 +194,7 @@
 
 #endif
 
+#ifndef __clang__
 #ifndef __m128d 
 #define __m128d x86_m128d
 #endif
@@ -197,5 +206,6 @@
 #ifndef __m128
 #define __m128 x86_m128
 #endif
+#endif
 
 #endif
