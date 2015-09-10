--- cpp/include/IceUtil/ScannerConfig.h.orig	2015-06-27 11:31:57.336119105 +0000
+++ cpp/include/IceUtil/ScannerConfig.h	2015-06-27 11:42:15.630073945 +0000
@@ -29,7 +29,7 @@
 // Clang++ >= 5.1  deprecate 'register' storage class specifier
 // used by lex generated Scanners.
 //
-#if defined(__clang__)
+#if defined(__clang__) && __clang_major__ >= 3 && __clang_minor__ >= 4
 #   pragma clang diagnostic ignored "-Wdeprecated-register"
 #endif
 
