--- src/iop/filmicrgb.c.orig	2023-01-27 09:19:36 UTC
+++ src/iop/filmicrgb.c
@@ -94,21 +94,6 @@ DT_MODULE_INTROSPECTION(6, dt_iop_filmicrgb_params_t)
  * */
 
 
-/** Note :
- * we use finite-math-only and fast-math because divisions by zero are manually avoided in the code
- * fp-contract=fast enables hardware-accelerated Fused Multiply-Add
- * the rest is loop reorganization and vectorization optimization
- **/
-#if defined(__GNUC__)
-#pragma GCC optimize("unroll-loops", "tree-loop-if-convert", "tree-loop-distribution", "no-strict-aliasing",      \
-                     "loop-interchange", "loop-nest-optimize", "tree-loop-im", "unswitch-loops",                  \
-                     "tree-loop-ivcanon", "ira-loop-pressure", "split-ivs-in-unroller",                           \
-                     "variable-expansion-in-unroller", "split-loops", "ivopts", "predictive-commoning",           \
-                     "tree-loop-linear", "loop-block", "loop-strip-mine", "finite-math-only", "fp-contract=fast", \
-                     "fast-math", "no-math-errno")
-#endif
-
-
 typedef enum dt_iop_filmicrgb_methods_type_t
 {
   DT_FILMIC_METHOD_NONE = 0,              // $DESCRIPTION: "no"
