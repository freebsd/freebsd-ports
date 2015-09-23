--- src/common/ssl.c.orig	2009-08-16 11:40:16.000000000 +0200
+++ src/common/ssl.c	2015-09-23 21:35:37.994436305 +0200
@@ -70,7 +70,8 @@ _SSL_context_init (void (*info_cb_func),
 
 	SSLeay_add_ssl_algorithms ();
 	SSL_load_error_strings ();
-	ctx = SSL_CTX_new (server ? SSLv3_server_method() : SSLv3_client_method ());
+	ctx = SSL_CTX_new (server ? SSLv23_server_method() : SSLv23_client_method ());
+	SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
 
 	SSL_CTX_set_session_cache_mode (ctx, SSL_SESS_CACHE_BOTH);
 	SSL_CTX_set_timeout (ctx, 300);
