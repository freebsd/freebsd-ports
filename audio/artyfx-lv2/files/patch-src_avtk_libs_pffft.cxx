--- src/avtk/libs/pffft.cxx.orig	2019-07-29 20:43:14 UTC
+++ src/avtk/libs/pffft.cxx
@@ -98,6 +98,7 @@
    Altivec support macros
 */
 #if !defined(PFFFT_SIMD_DISABLE) && (defined(__ppc__) || defined(__ppc64__))
+#include <altivec.h>
 typedef vector float v4sf;
 #  define SIMD_SZ 4
 #  define VZERO() ((vector float) vec_splat_u8(0))
@@ -113,8 +114,8 @@ inline v4sf ld_ps1(const float *p)
 #  define LD_PS1(p) ld_ps1(&p)
 #  define INTERLEAVE2(in1, in2, out1, out2) { v4sf tmp__ = vec_mergeh(in1, in2); out2 = vec_mergel(in1, in2); out1 = tmp__; }
 #  define UNINTERLEAVE2(in1, in2, out1, out2) {                           \
-    vector unsigned char vperm1 =  (vector unsigned char)(0,1,2,3,8,9,10,11,16,17,18,19,24,25,26,27); \
-    vector unsigned char vperm2 =  (vector unsigned char)(4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31); \
+    vector unsigned char vperm1 =  (vector unsigned char){0,1,2,3,8,9,10,11,16,17,18,19,24,25,26,27}; \
+    vector unsigned char vperm2 =  (vector unsigned char){4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31}; \
     v4sf tmp__ = vec_perm(in1, in2, vperm1); out2 = vec_perm(in1, in2, vperm2); out1 = tmp__; \
   }
 #  define VTRANSPOSE4(x0,x1,x2,x3) {              \
@@ -127,7 +128,7 @@ inline v4sf ld_ps1(const float *p)
     x2 = vec_mergeh(y1, y3);                    \
     x3 = vec_mergel(y1, y3);                    \
   }
-#  define VSWAPHL(a,b) vec_perm(a,b, (vector unsigned char)(16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15))
+#  define VSWAPHL(a,b) vec_perm(a,b, (vector unsigned char){16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15})
 #  define VALIGNED(ptr) ((((long)(ptr)) & 0xF) == 0)
 
 /*
