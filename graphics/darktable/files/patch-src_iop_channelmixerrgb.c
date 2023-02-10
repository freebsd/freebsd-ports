--- src/iop/channelmixerrgb.c.orig	2023-01-27 09:33:55 UTC
+++ src/iop/channelmixerrgb.c
@@ -49,23 +49,6 @@ DT_MODULE_INTROSPECTION(3, dt_iop_channelmixer_rgb_par
 
 DT_MODULE_INTROSPECTION(3, dt_iop_channelmixer_rgb_params_t)
 
-/** Note :
- * we use finite-math-only and fast-math because divisions by zero are manually avoided in the code
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
-                      "finite-math-only", "fp-contract=fast", "fast-math", \
-                      "tree-vectorize", "no-math-errno")
-#endif
-
 
 #define CHANNEL_SIZE 4
 #define INVERSE_SQRT_3 0.5773502691896258f
