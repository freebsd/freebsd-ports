--- src/net/networking.cc.orig	2012-08-24 16:47:58 UTC
+++ src/net/networking.cc
@@ -72,7 +72,8 @@ ssl_context (void)
     //BIO* bio_err = BIO_new_fp(stderr, BIO_NOCLOSE);
 
     /* Create SSL Context. */
-    SSL_CTX* ctx = SSL_CTX_new(SSLv3_client_method());
+    SSL_CTX* ctx = SSL_CTX_new(SSLv23_client_method());
+    SSL_CTX_set_options(ctx, SSL_OP_NO_SSL2)
 
     /* Load CAs we trust. */
 
