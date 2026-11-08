--- src/dotprod/src/dotprod_rrrf.av.c.orig	2023-06-19 22:04:12 UTC
+++ src/dotprod/src/dotprod_rrrf.av.c
@@ -26,6 +26,8 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
+#include <altivec.h>
 
 #include "liquid.internal.h"
 
@@ -117,7 +119,7 @@ dotprod_rrrf dotprod_rrrf_create_opt(float *      _h,
     for (i=0; i<4; i++) {
         q->h[i] = calloc(1+(q->n+i-1)/4,sizeof(vector float));
         for (j=0; j<q->n; j++)
-            e->h[i][j+i] = _h[_rev ? q->n-j-1 : j];
+            q->h[i][j+i] = _h[_rev ? q->n-j-1 : j];
     }
 
     return q;
@@ -155,6 +157,28 @@ dotprod_rrrf dotprod_rrrf_recreate_rev(dotprod_rrrf _q
     return dotprod_rrrf_create_rev(_h,_n);
 }
 
+// copy the structured dotprod object
+dotprod_rrrf dotprod_rrrf_copy(dotprod_rrrf q_orig)
+{
+    // validate input
+    if (q_orig == NULL)
+        return liquid_error_config("dotprod_rrrf_copy().av, object cannot be NULL");
+
+    dotprod_rrrf q_copy = (dotprod_rrrf)malloc(sizeof(struct dotprod_rrrf_s));
+    q_copy->n = q_orig->n;
+
+    // copy each of the four alignment-shifted coefficient arrays,
+    // matching the allocation performed by dotprod_rrrf_create_opt()
+    unsigned int i;
+    for (i=0; i<4; i++) {
+        unsigned int len = 1 + (q_copy->n + i - 1)/4;
+        q_copy->h[i] = calloc(len, sizeof(vector float));
+        memmove(q_copy->h[i], q_orig->h[i], len*(sizeof(vector float)));
+    }
+
+    return q_copy;
+}
+
 // destroy the structured dotprod object
 int dotprod_rrrf_destroy(dotprod_rrrf _q)
 {
@@ -190,8 +214,8 @@ int dotprod_rrrf_execute(dotprod_rrrf _q,
     union { vector float v; float w[4];} s;
     unsigned int nblocks;
 
-    ar = (vector float*)( (int)_x & ~15);
-    al = ((int)_x & 15)/sizeof(float);
+    ar = (vector float*)( (uintptr_t)_x & ~15);
+    al = ((uintptr_t)_x & 15)/sizeof(float);
 
     d = (vector float*)_q->h[al];
 
@@ -200,7 +224,7 @@ int dotprod_rrrf_execute(dotprod_rrrf _q,
     // split into four vectors each with four 32-bit
     // partial sums.  Effectively each loop iteration
     // operates on 16 input samples at a time.
-    s0 = s1 = s2 = s3 = (vector float)(0);
+    s0 = s1 = s2 = s3 = (vector float){0,0,0,0};
     while (nblocks >= 4) {
         s0 = vec_madd(ar[nblocks-1],d[nblocks-1],s0);
         s1 = vec_madd(ar[nblocks-2],d[nblocks-2],s1);
@@ -221,7 +245,7 @@ int dotprod_rrrf_execute(dotprod_rrrf _q,
     // move the result into the union s (effetively,
     // this loads the four 32-bit values in s0 into
     // the array w).
-    s.v = vec_add(s0,(vector float)(0));
+    s.v = vec_add(s0,(vector float){0,0,0,0});
 
     // sum the resulting array
     *_r = s.w[0] + s.w[1] + s.w[2] + s.w[3];
