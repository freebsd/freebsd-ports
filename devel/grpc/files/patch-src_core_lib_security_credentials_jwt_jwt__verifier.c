--- src/core/lib/security/credentials/jwt/jwt_verifier.c.orig	2017-10-05 19:05:39 UTC
+++ src/core/lib/security/credentials/jwt/jwt_verifier.c
@@ -462,7 +462,7 @@ static BIGNUM *bignum_from_base64(grpc_e
   return result;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 // Provide compatibility across OpenSSL 1.02 and 1.1.
 static int RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d) {
