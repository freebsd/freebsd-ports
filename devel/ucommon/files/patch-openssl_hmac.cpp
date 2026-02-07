--- openssl/hmac.cpp.orig	2015-10-11 02:32:36 UTC
+++ openssl/hmac.cpp
@@ -35,8 +35,12 @@ void HMAC::set(const char *digest, const secure::keyby
 
     hmactype = EVP_get_digestbyname(digest);
     if(hmactype && len) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        context = HMAC_CTX_new();
+#else
         context = new ::HMAC_CTX;
         HMAC_CTX_init((HMAC_CTX *)context);
+#endif
         HMAC_Init((HMAC_CTX *)context, *key, (int)len, (const EVP_MD *)hmactype);
     }
 }
@@ -44,9 +48,13 @@ void HMAC::set(const char *digest, const secure::keyby
 void HMAC::release(void)
 {
     if(context) {
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L
+        HMAC_CTX_free((HMAC_CTX *)context);
+#else
         HMAC_cleanup((HMAC_CTX *)context);
         memset(context, 0, sizeof(HMAC_CTX));
         delete (HMAC_CTX *)context;
+#endif
         context = NULL;
     }
 
