--- ext/openssl/openssl_missing.h.orig	2008-08-04 06:44:17.000000000 +0200
+++ ext/openssl/openssl_missing.h	2010-04-06 14:00:55.000000000 +0200
@@ -65,7 +65,7 @@
 #endif
 
 #if !defined(HAVE_HMAC_CTX_COPY)
-void HMAC_CTX_copy(HMAC_CTX *out, HMAC_CTX *in);
+int HMAC_CTX_copy(HMAC_CTX *out, HMAC_CTX *in);
 #endif
 
 #if !defined(HAVE_HMAC_CTX_CLEANUP)
@@ -89,7 +89,7 @@
 #endif
 
 #if !defined(HAVE_EVP_CIPHER_CTX_COPY)
-int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out, EVP_CIPHER_CTX *in);
+int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out, const EVP_CIPHER_CTX *in);
 #endif
 
 #if !defined(HAVE_EVP_DIGESTINIT_EX)
