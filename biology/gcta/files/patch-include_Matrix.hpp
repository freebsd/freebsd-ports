--- include/Matrix.hpp.orig	2022-08-03 06:01:52 UTC
+++ include/Matrix.hpp
@@ -32,7 +32,9 @@ bool _LLT(MatrixType &A, double &logdet){
 #if GCTA_CPU_x86
     dpotrf(&uplo, &cols, vi, &cols, &info);
 #else
-    dpotrf_(&uplo, &cols, vi, &cols, &info);
+    // OpenBLAS 0.3.25 requires a length argument.  Is 1 the right value?
+    // Should all dgeqrf_() calls be patched?
+    dpotrf_(&uplo, &cols, vi, &cols, &info, 1);
 #endif    
     //LOGGER << "  LLT time: " << LOGGER.tp("LLT") << std::endl;
     if(info == 0){
@@ -41,7 +43,9 @@ bool _LLT(MatrixType &A, double &logdet){
 #if GCTA_CPU_x86        
         dpotri(&uplo, &cols, vi, &cols, &info);
 #else
-        dpotri_(&uplo, &cols, vi, &cols, &info);
+        // OpenBLAS 0.3.25 requires a length argument.  Is 1 the right value?
+        // Should all doptri_() calls be patched?
+        dpotri_(&uplo, &cols, vi, &cols, &info, 1);
 #endif
         //LOGGER << "  LLT inverse time: " << LOGGER.tp("LLT_INV") << std::endl;
         if(info == 0){
