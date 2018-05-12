--- vio/viosslfactories.cc.orig	2018-04-08 06:44:49 UTC
+++ vio/viosslfactories.cc
@@ -37,6 +37,7 @@
 
 #ifdef HAVE_OPENSSL
 #include <openssl/dh.h>
+#include <openssl/crypto.h>
 
 #define TLS_VERSION_OPTION_SIZE 256
 #define SSL_CIPHER_LIST_SIZE 4096
@@ -135,7 +136,7 @@ static DH *get_dh2048(void) {
     BIGNUM *p = BN_bin2bn(dh2048_p, sizeof(dh2048_p), NULL);
     BIGNUM *g = BN_bin2bn(dh2048_g, sizeof(dh2048_g), NULL);
     if (!p || !g
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
         || !DH_set0_pqg(dh, p, NULL, g)
 #endif /* OPENSSL_VERSION_NUMBER >= 0x10100000L */
     ) {
@@ -143,7 +144,7 @@ static DH *get_dh2048(void) {
       DH_free(dh);
       return NULL;
     }
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dh->p = p;
     dh->g = g;
 #endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
@@ -426,7 +427,7 @@ void ssl_start() {
   }
 }
 
-#ifndef HAVE_WOLFSSL
+#if !defined(HAVE_WOLFSSL) && !defined(LIBRESSL_VERSION_NUMBER)
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -449,6 +450,10 @@ int set_fips_mode(const uint fips_mode, 
   int rc = -1;
   unsigned int fips_mode_old = -1;
   unsigned long err_library = 0;
+#if defined(LIBRESSL_VERSION_NUMBER)
+  err_string="LibreSSL deosn't have FIPS_mode functionas";
+  goto EXIT;
+#else
   if (fips_mode > 2) {
     goto EXIT;
   }
@@ -462,6 +467,7 @@ int set_fips_mode(const uint fips_mode, 
     ERR_error_string_n(err_library, err_string, OPENSSL_ERROR_LENGTH - 1);
     err_string[OPENSSL_ERROR_LENGTH - 1] = '\0';
   }
+#endif
 EXIT:
   return rc;
 }
