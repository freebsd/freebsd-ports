--- src/mongo/crypto/sha1_block_openssl.cpp.orig	2017-06-27 19:02:43 UTC
+++ src/mongo/crypto/sha1_block_openssl.cpp
@@ -42,7 +42,7 @@
 #include <openssl/evp.h>
 #include <openssl/hmac.h>
 #include <openssl/sha.h>
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 namespace {
 // Copies of OpenSSL after 1.1.0 define new EVP digest routines. We must
 // polyfill used definitions to interact with older OpenSSL versions.
