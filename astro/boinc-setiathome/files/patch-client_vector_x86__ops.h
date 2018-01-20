--- client/vector/x86_ops.h.orig	2018-01-14 23:02:12 UTC
+++ client/vector/x86_ops.h
@@ -137,8 +137,10 @@
 // SSE2 specific functions/macros here.
 #if defined(_MSC_VER) || defined(__clang__)
 typedef __m128d x86_m128d;
+typedef __m128i x86_m128i;
 #else
 typedef double x86_m128d __attribute__ ((mode(V2DF))) __attribute__((aligned(16)));
+typedef int x86_m128i __attribute__ ((mode(V4SI))) __attribute__((aligned(16)));
 #endif
 #endif
 
@@ -146,10 +148,8 @@ typedef double x86_m128d __attribute__ ((mode(V2DF))) 
 // SSE specific functions/macros here.
 #if defined(_MSC_VER) || defined(__clang__)
 typedef __m128 x86_m128;
-typedef __m128i x86_m128i;
 #else
 typedef float x86_m128 __attribute__ ((mode(V4SF))) __attribute__((aligned(16)));
-typedef int x86_m128i __attribute__ ((mode(V4SI))) __attribute__((aligned(16)));
 #endif
 
 static inline void prefetcht0(const void *v) {
