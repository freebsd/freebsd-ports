--- src/StatLib.cpp.orig	2022-08-03 06:01:52 UTC
+++ src/StatLib.cpp
@@ -1,3 +1,4 @@
+
 /*
    GCTA: a tool for Genome-wide Complex Trait Analysis
 
@@ -117,8 +118,10 @@ namespace StatLib{
         dormqr(&side, &t, &n, &n, &n, X, &lda, tau, c, 
                 &lda, work, &lwork, &info);
 #else
+        // OpenBLAS 0.3.25 requires a length argument.  Is 1 the right value?
+        // Should all dormqr_() calls be patched?
         dormqr_(&side, &t, &n, &n, &n, X, &lda, tau, c, 
-                &lda, work, &lwork, &info);
+                &lda, work, &lwork, &info, 1, 1);
 #endif
         if(info != 0){
             return false;
