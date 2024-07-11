--- src/dotprod/src/dotprod_crcf.av.c.orig	2024-06-19 07:24:39 UTC
+++ src/dotprod/src/dotprod_crcf.av.c
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <altivec.h>
 
 #include "liquid.internal.h"
 
@@ -195,8 +196,8 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     union { vector float v; float w[4];} s;
     unsigned int nblocks;
 
-    ar = (vector float*)( (int)_x & ~15);
-    al = ((int)_x & 15)/sizeof(float);
+    ar = (vector float*)( (uintptr_t)_x & ~15);
+    al = ((uintptr_t)_x & 15)/sizeof(float);
 
     d = (vector float*)_q->h[al];
 
@@ -206,7 +207,7 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     // split into four vectors each with four 32-bit
     // partial sums.  Effectively each loop iteration
     // operates on 16 input samples at a time.
-    s0 = s1 = s2 = s3 = (vector float)(0);
+    s0 = s1 = s2 = s3 = (vector float){0,0,0,0};
     while (nblocks >= 4) {
         s0 = vec_madd(ar[nblocks-1],d[nblocks-1],s0);
         s1 = vec_madd(ar[nblocks-2],d[nblocks-2],s1);
@@ -227,7 +228,7 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     // move the result into the union s (effetively,
     // this loads the four 32-bit values in s0 into
     // the array w).
-    s.v = vec_add(s0,(vector float)(0));
+    s.v = vec_add(s0,(vector float){0,0,0,0});
 
     // sum the resulting array
     //*_r = s.w[0] + s.w[1] + s.w[2] + s.w[3];
