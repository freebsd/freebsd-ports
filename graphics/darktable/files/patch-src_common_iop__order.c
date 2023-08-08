--- src/common/iop_order.c.orig	2023-07-06 21:18:18 UTC
+++ src/common/iop_order.c
@@ -37,23 +37,6 @@ static void _ioppr_reset_iop_order(GList *iop_order_li
 
 static void _ioppr_reset_iop_order(GList *iop_order_list);
 
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
 const char *iop_order_string[] =
 {
   N_("custom"),
