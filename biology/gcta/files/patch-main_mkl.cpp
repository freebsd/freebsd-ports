--- main/mkl.cpp.orig	2023-11-20 14:09:49 UTC
+++ main/mkl.cpp
@@ -365,7 +365,9 @@ bool gcta::comput_inverse_logdet_LDLT_mkl(eigenMatrix 
 #if GCTA_CPU_x86
     dpotrf(&uplo, &int_n, Vi_mkl, &int_n, &info);
 #else
-    dpotrf_(&uplo, &int_n, Vi_mkl, &int_n, &info);
+    // OpenBLAS 0.3.25 requires a length argument.  Is 1 the right value?
+    // Should all dpotrf_() calls be patched?
+    dpotrf_(&uplo, &int_n, Vi_mkl, &int_n, &info, 1);
 #endif
     //LOGGER << "Finished decompose" << endl;
     //spotrf( &uplo, &n, Vi_mkl, &n, &info );
@@ -386,7 +388,9 @@ bool gcta::comput_inverse_logdet_LDLT_mkl(eigenMatrix 
 #if GCTA_CPU_x86
         dpotri(&uplo, &int_n, Vi_mkl, &int_n, &info);
 #else
-        dpotri_(&uplo, &int_n, Vi_mkl, &int_n, &info);
+        // OpenBLAS 0.3.25 requires a length argument.  Is 1 the right value?
+        // Should all dpotri_() calls be patched?
+        dpotri_(&uplo, &int_n, Vi_mkl, &int_n, &info, 1);
 #endif
         //LOGGER << "Inverse finished" << endl;
         //spotri( &uplo, &n, Vi_mkl, &n, &info );
