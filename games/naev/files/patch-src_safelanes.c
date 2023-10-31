--- src/safelanes.c.orig	2023-07-09 05:08:54 UTC
+++ src/safelanes.c
@@ -10,6 +10,12 @@
 /** @cond */
 #include <math.h>
 
+#if HAVE_SUITESPARSE_CHOLMOD_H
+#include <suitesparse/cholmod.h>
+#else /* HAVE_SUITESPARSE_CHOLMOD_H */
+#include <cholmod.h>
+#endif /* HAVE_SUITESPARSE_CHOLMOD_H */
+
 #if HAVE_OPENBLAS_CBLAS_H
 #   include <openblas/cblas.h>
 #elif HAVE_CBLAS_OPENBLAS_H
@@ -24,12 +30,6 @@
 #   include <f77blas.h>
 #   define I_LOVE_FORTRAN 1
 #endif
-
-#if HAVE_SUITESPARSE_CHOLMOD_H
-#include <suitesparse/cholmod.h>
-#else /* HAVE_SUITESPARSE_CHOLMOD_H */
-#include <cholmod.h>
-#endif /* HAVE_SUITESPARSE_CHOLMOD_H */
 
 #include "naev.h"
 /** @endcond */
