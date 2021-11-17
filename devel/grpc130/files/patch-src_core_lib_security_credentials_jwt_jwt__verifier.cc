--- src/core/lib/security/credentials/jwt/jwt_verifier.cc.orig	2020-12-01 19:24:28 UTC
+++ src/core/lib/security/credentials/jwt/jwt_verifier.cc
@@ -472,7 +472,7 @@ static BIGNUM* bignum_from_base64(const char* b64) {
   return result;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 // Provide compatibility across OpenSSL 1.02 and 1.1.
 static int RSA_set0_key(RSA* r, BIGNUM* n, BIGNUM* e, BIGNUM* d) {
