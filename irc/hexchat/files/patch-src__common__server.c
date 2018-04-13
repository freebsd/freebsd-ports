--- src/common/server.c.orig	2018-03-14 02:26:31 UTC
+++ src/common/server.c
@@ -749,7 +749,7 @@ server_connect_success (server *serv)
 		/* it'll be a memory leak, if connection isn't terminated by
 		   server_cleanup() */
 		serv->ssl = _SSL_socket (serv->ctx, serv->sok);
-		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, NULL)))
+		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, "%%CA_BUNDLE%%")))
 		{
 			EMIT_SIGNAL (XP_TE_CONNFAIL, serv->server_session, err, NULL,
 							 NULL, NULL, 0);
