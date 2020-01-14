--- src/fastopenblas.h.orig	2018-12-11 05:34:29 UTC
+++ src/fastopenblas.h
@@ -23,10 +23,12 @@
 
 #include <assert.h>
 #include <iostream>
+/* Conflicts with gsl_cblas.h, included from gsl_matrix.h
 extern "C"
 {
    #include <cblas.h>   // For OpenBlas / Atlas
 }
+*/
 #include "gsl/gsl_matrix.h"
 
 void fast_cblas_dgemm(const enum CBLAS_ORDER Order,
