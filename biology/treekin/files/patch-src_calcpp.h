--- src/calcpp.h.orig	2019-06-13 14:11:19 UTC
+++ src/calcpp.h
@@ -49,6 +49,9 @@
 # include <lapacke.h>
 #else
 # ifdef HAVE_LAPACKE_LAPACKE_H
+#   include <complex>
+#   define lapack_complex_float std::complex<float>
+#   define lapack_complex_double std::complex<double>
 #   include <lapacke/lapacke.h>
 # else
 #   ifdef HAVE_OPENBLAS_LAPACKE_H
