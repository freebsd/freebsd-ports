--- src/core.c.orig	2019-08-29 17:26:06 UTC
+++ src/core.c
@@ -651,7 +651,7 @@ recv_done(Call * call)
 static void
 do_recv(Conn * s)
 {
-	char           *cp, buf[8193];
+	char           *cp, buf[16385];
 	Call           *c = s->recvq;
 	int             i, saved_errno;
 	ssize_t         nread = 0;
@@ -1062,8 +1062,7 @@ core_ssl_connect(Conn * s)
 		exit(-1);
 	}
 
-	ssl_err = SSL_connect(s->ssl);
-	if (ssl_err < 0) {
+	while ((ssl_err = SSL_connect(s->ssl)) < 0) {
 		int             reason = SSL_get_error(s->ssl, ssl_err);
 
 		if (reason == SSL_ERROR_WANT_READ
@@ -1083,7 +1082,7 @@ core_ssl_connect(Conn * s)
 				clear_active(s, READ);
 				set_active(s, WRITE);
 			}
-			return;
+			continue;
 		}
 		fprintf(stderr,
 			"%s: failed to connect to SSL server (err=%d, reason=%d)\n",
