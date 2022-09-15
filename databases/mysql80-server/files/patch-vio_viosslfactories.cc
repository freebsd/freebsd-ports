--- vio/viosslfactories.cc.orig	2022-07-06 21:36:34 UTC
+++ vio/viosslfactories.cc
@@ -40,6 +40,7 @@
 #include "vio/vio_priv.h"
 
 #include <openssl/dh.h>
+#include <openssl/crypto.h>
 
 #if OPENSSL_VERSION_NUMBER < 0x10002000L
 #include <openssl/ec.h>
@@ -484,7 +485,7 @@ long process_tls_version(const char *tls_version) {
   const char *separator = ",";
   char *token, *lasts = nullptr;
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   const char *tls_version_name_list[] = {"TLSv1.2", "TLSv1.3"};
   const char ctx_flag_default[] = "TLSv1.2,TLSv1.3";
   const long tls_ctx_list[] = {SSL_OP_NO_TLSv1_2, SSL_OP_NO_TLSv1_3};
@@ -559,7 +560,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
   ssl_ctx_options = (ssl_ctx_options | ssl_ctx_flags) &
                     (SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1 |
                      SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                      | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                      | SSL_OP_NO_TICKET);
@@ -568,7 +569,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
     return nullptr;
 
   if (!(ssl_fd->ssl_context = SSL_CTX_new(is_client ?
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                                                     TLS_client_method()
                                                     : TLS_server_method()
 #else  /* HAVE_TLSv13 */
@@ -583,7 +584,7 @@ static struct st_VioSSLFd *new_VioSSLFd(
     return nullptr;
   }
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /*
     Set OpenSSL TLS v1.3 ciphersuites.
     Note that an empty list is permissible.
