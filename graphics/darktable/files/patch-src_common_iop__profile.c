--- src/common/iop_profile.c.orig	2023-07-06 21:19:34 UTC
+++ src/common/iop_profile.c
@@ -34,24 +34,6 @@
 #include <stdlib.h>
 #include <string.h>
 
-/** Note : we do not use finite-math-only and fast-math because
- * divisions by zero are not manually avoided in the code
- * fp-contract=fast enables hardware-accelerated Fused Multiply-Add
- * the rest is loop reorganization and vectorization optimization
- **/
-#if defined(__GNUC__)
-#pragma GCC optimize ("unroll-loops", "tree-loop-if-convert", \
-                      "tree-loop-distribution", "no-strict-aliasing", \
-                      "loop-interchange", "loop-nest-optimize", "tree-loop-im", \
-                      "unswitch-loops", "tree-loop-ivcanon", "ira-loop-pressure", \
-                      "split-ivs-in-unroller", "variable-expansion-in-unroller", \
-                      "split-loops", "ivopts", "predictive-commoning",\
-                      "tree-loop-linear", "loop-block", "loop-strip-mine", \
-                      "fp-contract=fast", \
-                      "tree-vectorize")
-#endif
-
-
 static void _mark_as_nonmatrix_profile(dt_iop_order_iccprofile_info_t *const profile_info)
 {
   dt_mark_colormatrix_invalid(&profile_info->matrix_in[0][0]);
