--- src/libmpd.c.orig	Sat Jun 23 00:31:14 2007
+++ src/libmpd.c	Sat Jun 23 00:31:42 2007
@@ -420,6 +420,7 @@ void mpd_disconnect(mpd_connection *mpd_conn)
 
 	shutdown(mpd_conn->sockd, SHUT_RDWR);
 	close(mpd_conn->sockd);
+	mpd_conn->status = DISCONNECTED;
 }
 
 int mpd_check_server(mpd_connection *mpd_conn, struct s_exception *e)
