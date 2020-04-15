--- mkl.cpp.orig	2020-04-15 00:54:40 UTC
+++ mkl.cpp
@@ -357,7 +357,7 @@ bool gcta::comput_inverse_logdet_LDLT_mkl(eigenMatrix 
     // MKL's Cholesky decomposition
     int info = 0, int_n = (int) n;
     char uplo = 'L';
-    dpotrf(&uplo, &int_n, Vi_mkl, &int_n, &info);
+    dpotrf_(&uplo, &int_n, Vi_mkl, &int_n, &info);
     //spotrf( &uplo, &n, Vi_mkl, &n, &info );
     if (info < 0) throw ("Error: Cholesky decomposition failed. Invalid values found in the matrix.\n");
     else if (info > 0) return false;
@@ -369,7 +369,7 @@ bool gcta::comput_inverse_logdet_LDLT_mkl(eigenMatrix 
         }
 
         // Calcualte V inverse
-        dpotri(&uplo, &int_n, Vi_mkl, &int_n, &info);
+        dpotri_(&uplo, &int_n, Vi_mkl, &int_n, &info);
         //spotri( &uplo, &n, Vi_mkl, &n, &info );
         if (info < 0) throw ("Error: invalid values found in the varaince-covaraince (V) matrix.\n");
         else if (info > 0) return false;
@@ -405,7 +405,7 @@ bool gcta::comput_inverse_logdet_LU_mkl(eigenMatrix &V
     int LWORK = N*N;
     double *WORK = new double[n * n];
     int INFO;
-    dgetrf(&N, &N, Vi_mkl, &N, IPIV, &INFO);
+    dgetrf_(&N, &N, Vi_mkl, &N, IPIV, &INFO);
     if (INFO < 0) throw ("Error: LU decomposition failed. Invalid values found in the matrix.\n");
     else if (INFO > 0) {
         delete[] Vi_mkl;
@@ -418,7 +418,7 @@ bool gcta::comput_inverse_logdet_LU_mkl(eigenMatrix &V
         }
 
         // Calcualte V inverse
-        dgetri(&N, Vi_mkl, &N, IPIV, WORK, &LWORK, &INFO);
+        dgetri_(&N, Vi_mkl, &N, IPIV, WORK, &LWORK, &INFO);
         if (INFO < 0) throw ("Error: invalid values found in the varaince-covaraince (V) matrix.\n");
         else if (INFO > 0) return false;
         else {
@@ -453,7 +453,7 @@ bool gcta::comput_inverse_logdet_LU_mkl_array(int n, f
     int LWORK = N*N;
     double *WORK = new double[n * n];
     int INFO;
-    dgetrf(&N, &N, Vi_mkl, &N, IPIV, &INFO);
+    dgetrf_(&N, &N, Vi_mkl, &N, IPIV, &INFO);
     if (INFO < 0) throw ("Error: LU decomposition failed. Invalid values found in the matrix.\n");
     else if (INFO > 0) {
         delete[] Vi_mkl;
@@ -467,7 +467,7 @@ bool gcta::comput_inverse_logdet_LU_mkl_array(int n, f
         }
 
         // Calcualte V inverse
-        dgetri(&N, Vi_mkl, &N, IPIV, WORK, &LWORK, &INFO);
+        dgetri_(&N, Vi_mkl, &N, IPIV, WORK, &LWORK, &INFO);
         if (INFO < 0) throw ("Error: invalid values found in the varaince-covaraince (V) matrix.\n");
         else if (INFO > 0) return (false); // Vi.diagonal()=Vi.diagonal().array()+Vi.diagonal().mean()*1e-3;
         else {
