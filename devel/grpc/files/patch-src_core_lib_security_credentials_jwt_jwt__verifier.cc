--- src/core/lib/security/credentials/jwt/jwt_verifier.cc.orig	2018-09-24 23:51:30 UTC
+++ src/core/lib/security/credentials/jwt/jwt_verifier.cc
@@ -468,7 +468,7 @@ static BIGNUM* bignum_from_base64(const char* b64) {
   return result;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 // Provide compatibility across OpenSSL 1.02 and 1.1.
 static int RSA_set0_key(RSA* r, BIGNUM* n, BIGNUM* e, BIGNUM* d) {
