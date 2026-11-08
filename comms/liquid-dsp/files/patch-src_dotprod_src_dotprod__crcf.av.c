--- src/dotprod/src/dotprod_crcf.av.c.orig	2023-06-19 22:04:12 UTC
+++ src/dotprod/src/dotprod_crcf.av.c
@@ -26,6 +26,8 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
+#include <altivec.h>
 
 #include "liquid.internal.h"
 
@@ -160,6 +162,28 @@ dotprod_crcf dotprod_crcf_recreate_rev(dotprod_crcf _q
     return dotprod_crcf_create_rev(_h,_n);
 }
 
+// copy the structured dotprod object
+dotprod_crcf dotprod_crcf_copy(dotprod_crcf q_orig)
+{
+    // validate input
+    if (q_orig == NULL)
+        return liquid_error_config("dotprod_crcf_copy().av, object cannot be NULL");
+
+    dotprod_crcf q_copy = (dotprod_crcf)malloc(sizeof(struct dotprod_crcf_s));
+    q_copy->n = q_orig->n;
+
+    // copy each of the four alignment-shifted coefficient arrays,
+    // matching the allocation performed by dotprod_crcf_create_opt()
+    unsigned int i;
+    for (i=0; i<4; i++) {
+        unsigned int len = 1 + (2*q_copy->n + i - 1)/4;
+        q_copy->h[i] = calloc(len, 2*sizeof(vector float));
+        memmove(q_copy->h[i], q_orig->h[i], len*(2*sizeof(vector float)));
+    }
+
+    return q_copy;
+}
+
 // destroy the structured dotprod object
 int dotprod_crcf_destroy(dotprod_crcf _q)
 {
@@ -195,8 +219,8 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     union { vector float v; float w[4];} s;
     unsigned int nblocks;
 
-    ar = (vector float*)( (int)_x & ~15);
-    al = ((int)_x & 15)/sizeof(float);
+    ar = (vector float*)( (uintptr_t)_x & ~15);
+    al = ((uintptr_t)_x & 15)/sizeof(float);
 
     d = (vector float*)_q->h[al];
 
@@ -206,7 +230,7 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     // split into four vectors each with four 32-bit
     // partial sums.  Effectively each loop iteration
     // operates on 16 input samples at a time.
-    s0 = s1 = s2 = s3 = (vector float)(0);
+    s0 = s1 = s2 = s3 = (vector float){0,0,0,0};
     while (nblocks >= 4) {
         s0 = vec_madd(ar[nblocks-1],d[nblocks-1],s0);
         s1 = vec_madd(ar[nblocks-2],d[nblocks-2],s1);
@@ -227,7 +251,7 @@ int dotprod_crcf_execute(dotprod_crcf    _q,
     // move the result into the union s (effetively,
     // this loads the four 32-bit values in s0 into
     // the array w).
-    s.v = vec_add(s0,(vector float)(0));
+    s.v = vec_add(s0,(vector float){0,0,0,0});
 
     // sum the resulting array
     //*_r = s.w[0] + s.w[1] + s.w[2] + s.w[3];
