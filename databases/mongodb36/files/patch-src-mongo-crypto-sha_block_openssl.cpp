--- src/mongo/crypto/sha_block_openssl.cpp.orig	2018-07-08 16:42:41.034894000 +0000
+++ src/mongo/crypto/sha_block_openssl.cpp	2018-07-08 16:42:58.121846000 +0000
@@ -44,7 +44,7 @@
 #include <openssl/hmac.h>
 #include <openssl/sha.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 namespace {
 // Copies of OpenSSL after 1.1.0 define new EVP digest routines. We must
 // polyfill used definitions to interact with older OpenSSL versions.
