--- vio/viosslfactories.cc.orig	2019-09-20 08:30:51 UTC
+++ vio/viosslfactories.cc
@@ -38,6 +38,7 @@
 
 #ifdef HAVE_OPENSSL
 #include <openssl/dh.h>
+#include <openssl/crypto.h>
 
 #define TLS_VERSION_OPTION_SIZE 256
 #define SSL_CIPHER_LIST_SIZE 4096
@@ -420,6 +421,7 @@ void ssl_start() {
   }
 }
 
+#ifndef LIBRESSL_VERSION_NUMBER
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -473,6 +475,7 @@ EXIT:
   @returns openssl current fips mode
 */
 uint get_fips_mode() { return FIPS_mode(); }
+#endif
 
 long process_tls_version(const char *tls_version) {
   const char *separator = ",";
