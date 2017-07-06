--- src/mongo/crypto/crypto_openssl.cpp.orig	2017-06-08 16:11:03 UTC
+++ src/mongo/crypto/crypto_openssl.cpp
@@ -41,7 +41,7 @@
 #include <openssl/evp.h>
 #include <openssl/hmac.h>
 #include <openssl/sha.h>
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined (LIBRESSL_VERSION_NUMBER)
 namespace {
 // Copies of OpenSSL after 1.1.0 define new EVP digest routines. We must
 // polyfill used definitions to interact with older OpenSSL versions.
