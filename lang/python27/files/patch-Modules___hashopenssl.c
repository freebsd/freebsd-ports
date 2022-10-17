--- Modules/_hashopenssl.c.orig	2022-10-17 10:25:01 UTC
+++ Modules/_hashopenssl.c
@@ -56,7 +56,7 @@
 #define _OPENSSL_SUPPORTS_SHA2
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
 /* OpenSSL < 1.1.0 */
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
@@ -901,7 +901,7 @@ init_hashlib(void)
 {
     PyObject *m, *openssl_md_meth_names;
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
     /* Load all digest algorithms and initialize cpuid */
     OPENSSL_add_all_algorithms_noconf();
     ERR_load_crypto_strings();
