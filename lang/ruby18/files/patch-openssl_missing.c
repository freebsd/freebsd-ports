--- ./ext/openssl/openssl_missing.c.orig	2008-05-19 03:00:52.000000000 +0000
+++ ./ext/openssl/openssl_missing.c	2012-01-17 05:09:13.816807984 +0000
@@ -22,15 +22,16 @@
 #include "openssl_missing.h"
 
 #if !defined(HAVE_HMAC_CTX_COPY)
-void
+int
 HMAC_CTX_copy(HMAC_CTX *out, HMAC_CTX *in)
 {
-    if (!out || !in) return;
+    if (!out || !in) return 0;
     memcpy(out, in, sizeof(HMAC_CTX));
 
     EVP_MD_CTX_copy(&out->md_ctx, &in->md_ctx);
     EVP_MD_CTX_copy(&out->i_ctx, &in->i_ctx);
     EVP_MD_CTX_copy(&out->o_ctx, &in->o_ctx);
+    return 0;
 }
 #endif /* HAVE_HMAC_CTX_COPY */
 #endif /* NO_HMAC */
@@ -117,7 +118,7 @@
  * tested on 0.9.7d.
  */
 int
-EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out, EVP_CIPHER_CTX *in)
+EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out, const EVP_CIPHER_CTX *in)
 {
     memcpy(out, in, sizeof(EVP_CIPHER_CTX));
 
