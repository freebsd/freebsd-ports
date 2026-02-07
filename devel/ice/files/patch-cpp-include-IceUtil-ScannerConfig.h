--- cpp/include/IceUtil/ScannerConfig.h.orig	2019-08-12 19:54:18 UTC
+++ cpp/include/IceUtil/ScannerConfig.h
@@ -29,7 +29,7 @@
 // Clang++ >= 5.1  deprecate 'register' storage class specifier
 // used by lex generated Scanners.
 //
-#if defined(__clang__)
+#if defined(__clang__) && __clang_major__ >= 3 && __clang_minor__ >= 4
 #   pragma clang diagnostic ignored "-Wdeprecated-register"
 #endif
 
