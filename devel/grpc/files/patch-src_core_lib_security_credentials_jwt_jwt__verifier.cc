--- src/core/lib/security/credentials/jwt/jwt_verifier.cc.orig	2018-02-01 19:36:08 UTC
+++ src/core/lib/security/credentials/jwt/jwt_verifier.cc
@@ -463,7 +463,7 @@ static BIGNUM* bignum_from_base64(const 
   return result;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 
 // Provide compatibility across OpenSSL 1.02 and 1.1.
 static int RSA_set0_key(RSA* r, BIGNUM* n, BIGNUM* e, BIGNUM* d) {
