--- shout.c.orig	2000-04-20 07:31:50 UTC
+++ shout.c
@@ -1738,7 +1738,7 @@ login ()
 void
 update_meta_info_on_server (char *filename, unsigned long int size)
 {
-	sock_t sockfd = sock_connect (set.servername, set.port);
+	sock_t sockfd = sock_connect (set.servername, set.port-1);
 	char title[BUFSIZE];	/* copy of filename */
 	char *song = NULL;
 	char *mount = NULL;
@@ -1815,7 +1815,7 @@ update_meta_info_on_server (char *filena
 
 	if (sockfd != -1) {
 		if (set.use_icy) {
-			sock_write (sockfd, "GET /admin.cgi?pass=%s&mode=updinfo&song=%s HTTP/1.0\nHost: %s:%d\nUser-Agent: Shout/%s\n\n", set.password, url_encode (titleptr, &song), set.servername, set.port, VERSION);
+			sock_write (sockfd, "GET /admin.cgi?pass=%s&mode=updinfo&song=%s HTTP/1.0\nHost: %s:%d\nUser-Agent: Mozilla(Shout/%s)\n\n", set.password, url_encode (titleptr, &song), set.servername, set.port, VERSION);
 		} else {
 			sock_write (sockfd, "GET /admin.cgi?pass=%s&mode=updinfo&mount=%s&song=%s&length=%ld HTTP/1.0\nHost: %s:%d\nUser-Agent: Shout/%s\n\n", set.password, url_encode (set.mount_name, &mount), url_encode (titleptr, &song), size, set.servername, set.port, VERSION);
 			if (mount)
