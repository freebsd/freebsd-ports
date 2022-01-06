--- deps/ntlmclient/crypt_openssl.c.orig	2022-01-06 08:12:56 UTC
+++ deps/ntlmclient/crypt_openssl.c
@@ -44,7 +44,7 @@ static inline void HMAC_CTX_free(HMAC_CTX *ctx)
 
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L || defined(CRYPT_OPENSSL_DYNAMIC)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !LIBRESSL_VERSION_NUMBER) || defined(CRYPT_OPENSSL_DYNAMIC)
 
 static inline void HMAC_CTX_cleanup(HMAC_CTX *ctx)
 {
