--- vio/viosslfactories.cc.orig	2024-04-10 06:26:28 UTC
+++ vio/viosslfactories.cc
@@ -46,6 +46,7 @@
 #include <tls_ciphers.h>
 
 #include "my_openssl_fips.h"
+#include "openssl/crypto.h"
 #define TLS_VERSION_OPTION_SIZE 256
 
 static bool ssl_initialized = false;
@@ -334,7 +335,7 @@ long process_tls_version(const char *tls_version) {
   const char *separator = ",";
   char *token, *lasts = nullptr;
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   const char *tls_version_name_list[] = {"TLSv1.2", "TLSv1.3"};
   const char ctx_flag_default[] = "TLSv1.2,TLSv1.3";
   const long tls_ctx_list[] = {SSL_OP_NO_TLSv1_2, SSL_OP_NO_TLSv1_3};
@@ -405,7 +406,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
   ssl_ctx_options = (ssl_ctx_options | ssl_ctx_flags) &
                     (SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1 |
                      SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                      | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                      | SSL_OP_NO_TICKET);
@@ -414,7 +415,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
     return nullptr;
 
   if (!(ssl_fd->ssl_context = SSL_CTX_new(is_client ?
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                                                     TLS_client_method()
                                                     : TLS_server_method()
 #else  /* HAVE_TLSv13 */
@@ -429,7 +430,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
     return nullptr;
   }
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /*
     Set OpenSSL TLS v1.3 ciphersuites.
     Note that an empty list is permissible.
