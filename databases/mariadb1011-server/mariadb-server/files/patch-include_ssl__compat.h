--- include/ssl_compat.h.orig	2022-02-10 20:17:08 UTC
+++ include/ssl_compat.h
@@ -19,7 +19,8 @@
 /* OpenSSL version specific definitions */
 #if defined(OPENSSL_VERSION_NUMBER)
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
+	!(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x30500000) 
 #define HAVE_OPENSSL11 1
 #define SSL_LIBRARY OpenSSL_version(OPENSSL_VERSION)
 #define ERR_remove_state(X) ERR_clear_error()
@@ -73,7 +74,8 @@
 #define EVP_MD_CTX_SIZE                 sizeof(EVP_MD_CTX)
 #endif
 
-#ifndef DH_set0_pqg
+#if !defined(DH_set0_pqg) && \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x30500000)
 #define DH_set0_pqg(D,P,Q,G)            ((D)->p= (P), (D)->g= (G))
 #endif
 
