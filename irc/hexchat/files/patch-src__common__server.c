--- src/common/server.c.orig	2014-11-25 18:42:31.000000000 +0100
+++ src/common/server.c	2015-05-21 15:48:24.162789182 +0200
@@ -875,7 +875,7 @@
 		/* it'll be a memory leak, if connection isn't terminated by
 		   server_cleanup() */
 		serv->ssl = _SSL_socket (serv->ctx, serv->sok);
-		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, NULL)))
+		if ((err = _SSL_set_verify (serv->ctx, ssl_cb_verify, %%CA_BUNDLE%%)))
 		{
 			EMIT_SIGNAL (XP_TE_CONNFAIL, serv->server_session, err, NULL,
 							 NULL, NULL, 0);
