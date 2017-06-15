--- src/common/server.c.orig	2016-12-10 14:30:51 UTC
+++ src/common/server.c
@@ -743,7 +743,7 @@ server_connect_success (server *serv)
 		/* it'll be a memory leak, if connection isn't terminated by
 		   server_cleanup() */
 		serv->ssl = _SSL_socket (serv->ctx, serv->sok);
-		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, NULL)))
+		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, "/usr/local/share/certs/ca-root-nss.crt")))
 		{
 			EMIT_SIGNAL (XP_TE_CONNFAIL, serv->server_session, err, NULL,
 							 NULL, NULL, 0);
