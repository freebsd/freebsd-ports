--- src/common/extra_optimizations.h.orig	2022-12-14 15:18:18 UTC
+++ src/common/extra_optimizations.h
@@ -17,19 +17,3 @@
 */
 
 #pragma once
-
-/* Enable extra optimizations on GCC by including this header at the very
- * beginning of your *.c file (before any other includes). This applies
- * these optimizations for all of the source file.
- *
- * we use finite-math-only because divisions by zero are manually avoided
- * in the code, the rest is loop reorganization and vectorization optimization
- **/
-
-#if defined(__GNUC__)
-#pragma GCC optimize ("unroll-loops", "split-loops", \
-                      "loop-nest-optimize", "tree-loop-im", \
-                      "tree-loop-ivcanon", "ira-loop-pressure", \
-                      "variable-expansion-in-unroller", \
-                      "ivopts", "finite-math-only")
-#endif
