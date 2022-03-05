--- vio/viosslfactories.cc.orig	2021-12-17 08:07:27.000000000 -0800
+++ vio/viosslfactories.cc	2022-02-20 11:48:11.223957000 -0800
@@ -40,6 +40,7 @@
 #include "vio/vio_priv.h"
 
 #include <openssl/dh.h>
+#include <openssl/crypto.h>
 
 #if OPENSSL_VERSION_NUMBER < 0x10002000L
 #include <openssl/ec.h>
@@ -472,6 +473,7 @@
   }
 }
 
+#ifndef LIBRESSL_VERSION_NUMBER
 /**
   Set fips mode in openssl library,
   When we set fips mode ON/STRICT, it will perform following operations:
@@ -525,6 +527,7 @@
   @returns openssl current fips mode
 */
 uint get_fips_mode() { return FIPS_mode(); }
+#endif
 
 /**
   Toggle FIPS mode, to see whether it is available with the current SSL library.
@@ -532,6 +535,7 @@
   @retval non-zero: FIPS is supported.
 */
 int test_ssl_fips_mode(char *err_string) {
+#ifndef LIBRESSL_VERSION_NUMBER
   int ret = FIPS_mode_set(FIPS_mode() == 0 ? 1 : 0);
   unsigned long err = (ret == 0) ? ERR_get_error() : 0;
 
@@ -539,13 +543,16 @@
     ERR_error_string_n(err, err_string, OPENSSL_ERROR_LENGTH - 1);
   }
   return ret;
+#else
+  return 0;
+#endif
 }
 
 long process_tls_version(const char *tls_version) {
   const char *separator = ",";
   char *token, *lasts = nullptr;
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   const char *tls_version_name_list[] = {"TLSv1.2", "TLSv1.3"};
   const char ctx_flag_default[] = "TLSv1.2,TLSv1.3";
   const long tls_ctx_list[] = {SSL_OP_NO_TLSv1_2, SSL_OP_NO_TLSv1_3};
@@ -623,7 +630,7 @@
   ssl_ctx_options = (ssl_ctx_options | ssl_ctx_flags) &
                     (SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1 |
                      SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                      | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                      | SSL_OP_NO_TICKET);
@@ -632,7 +639,7 @@
     return nullptr;
 
   if (!(ssl_fd->ssl_context = SSL_CTX_new(is_client ?
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                                                     TLS_client_method()
                                                     : TLS_server_method()
 #else  /* HAVE_TLSv13 */
@@ -647,7 +654,7 @@
     return nullptr;
   }
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /*
     Set OpenSSL TLS v1.3 ciphersuites.
     Note that an empty list is permissible.
