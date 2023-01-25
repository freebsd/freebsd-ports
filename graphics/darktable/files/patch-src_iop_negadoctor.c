--- src/iop/negadoctor.c.orig	2023-01-27 09:34:21 UTC
+++ src/iop/negadoctor.c
@@ -40,17 +40,6 @@
 #include <math.h>
 #include <stdlib.h>
 
-#if defined(__GNUC__)
-#pragma GCC optimize ("unroll-loops", "tree-loop-if-convert", \
-                      "tree-loop-distribution", "no-strict-aliasing", \
-                      "loop-interchange", "loop-nest-optimize", "tree-loop-im", \
-                      "unswitch-loops", "tree-loop-ivcanon", "ira-loop-pressure", \
-                      "split-ivs-in-unroller", "variable-expansion-in-unroller", \
-                      "split-loops", "ivopts", "predictive-commoning",\
-                      "tree-loop-linear", "loop-block", "loop-strip-mine", \
-                      "finite-math-only", "fp-contract=fast", "fast-math")
-#endif
-
 /** DOCUMENTATION
  *
  * This module allows to invert scanned negatives and simulate their print on paper, based on Kodak Cineon
