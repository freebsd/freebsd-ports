--- ./src/common/server.c.orig	2013-09-12 00:18:19.000000000 +0200
+++ ./src/common/server.c	2014-04-12 16:12:48.778585855 +0200
@@ -862,7 +862,7 @@
 		/* it'll be a memory leak, if connection isn't terminated by
 		   server_cleanup() */
 		serv->ssl = _SSL_socket (ctx, serv->sok);
-		if ((err = _SSL_set_verify (ctx, ssl_cb_verify, NULL)))
+		if ((err = _SSL_set_verify (ctx, ssl_cb_verify, %%CA_BUNDLE%%)))
 		{
 			EMIT_SIGNAL (XP_TE_CONNFAIL, serv->server_session, err, NULL,
 							 NULL, NULL, 0);
