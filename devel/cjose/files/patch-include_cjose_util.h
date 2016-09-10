--- include/cjose/util.h.orig	2016-08-04 17:08:47 UTC
+++ include/cjose/util.h
@@ -25,7 +25,9 @@ extern "C"
 {
 #endif
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define CJOSE_OPENSSL_11X  OPENSSL_VERSION_NUMBER >= 0x10100005L
+#endif
 
 /**
  * Macro to explicitly mark a parameter unused, and usable across multiple
