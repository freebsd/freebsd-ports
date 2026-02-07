--- libratbox/src/openssl.c.orig	2024-07-01 21:36:08 UTC
+++ libratbox/src/openssl.c
@@ -299,7 +299,7 @@ rb_init_ssl(void)
 	/* Disable SSLv2, make the client use our settings */
 	SSL_CTX_set_options(ssl_server_ctx, SSL_OP_NO_SSLv2 | SSL_OP_CIPHER_SERVER_PREFERENCE);
 
-	ssl_client_ctx = SSL_CTX_new(TLSv1_client_method());
+	ssl_client_ctx = SSL_CTX_new(TLS_client_method());
 
 	if(ssl_client_ctx == NULL)
 	{
