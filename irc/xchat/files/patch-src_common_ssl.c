--- src/common/ssl.c.orig	2009-08-16 11:40:16.000000000 +0200
+++ src/common/ssl.c	2015-09-26 16:13:10.740904871 +0200
@@ -70,7 +70,8 @@ _SSL_context_init (void (*info_cb_func),
 
 	SSLeay_add_ssl_algorithms ();
 	SSL_load_error_strings ();
-	ctx = SSL_CTX_new (server ? SSLv3_server_method() : SSLv3_client_method ());
+	ctx = SSL_CTX_new (server ? SSLv23_server_method() : SSLv23_client_method ());
+	SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
 
 	SSL_CTX_set_session_cache_mode (ctx, SSL_SESS_CACHE_BOTH);
 	SSL_CTX_set_timeout (ctx, 300);
@@ -281,7 +282,7 @@ _SSL_socket (SSL_CTX *ctx, int sd)
 		__SSL_critical_error ("SSL_new");
 
 	SSL_set_fd (ssl, sd);
-	if (ctx->method == SSLv3_client_method())
+	if (ctx->method == SSLv23_client_method())
 		SSL_set_connect_state (ssl);
 	else
 	        SSL_set_accept_state(ssl);
