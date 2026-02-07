--- http/http_server.c.orig	2009-05-13 21:36:02 UTC
+++ http/http_server.c
@@ -171,7 +171,7 @@ http_server_start(struct pevent_ctx *ctx, struct in_ad
 		_http_ssl_init();
 
 		/* Initialize SSL context for this server */
-		if ((serv->ssl = SSL_CTX_new(SSLv2_server_method())) == NULL) {
+		if ((serv->ssl = SSL_CTX_new(SSLv23_server_method())) == NULL) {
 			ssl_log(http_server_ssl_logger, serv);
 			goto fail;
 		}
