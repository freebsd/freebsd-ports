- patch for latest breaking Lapack API changes, see https://github.com/Reference-LAPACK/lapack/issues/604#issuecomment-944069793

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
@@ -311,7 +314,8 @@ Calccpp::Mx_Dsyevx(const char *jobz,
       /*default standard lapack */
       ::dsyevx_((char *)jobz, (char *)range, (char *)uplo, n, (double *)a, lda, (double *)vl,
               (double *)vu, il, iu, (double *)abstol, m, (double *)w,
-              (double *)z, ldz, (double *)work, lwork, iwork, ifail, info);
+              (double *)z, ldz, (double *)work, lwork, iwork, ifail, info,
+              int(0) /*jobz_int*/, int(0) /*range_int*/, int(0) /*uplo_int*/); // "int" after the "info" parameter for each "char*" argument in the list
       break;
   }
 }
@@ -367,7 +371,8 @@ Calccpp::Mx_Dgeevx(const char *balanc,
               (double *)wr, (double *)wi, (double *)vl, ldvl,
               (double *)vr, ldvr, ilo, ihi, (double *)scale, (double *)abnrm, (double *)rconde,
               (double *)rcondv, (double *)work,
-              lwork, iwork, info);
+              lwork, iwork, info,
+              int(0) /*balanc_int*/, int(0) /*jobvl_int*/, int(0) /*jobvr_int*/, int(0) /*sense_int*/); // "int" after the "info" parameter for each "char*" argument in the list
       break;
   }
 }
