--- src/examples/srvcore.c.orig	2001-12-13 21:11:15 UTC
+++ src/examples/srvcore.c
@@ -381,7 +381,7 @@ SOCKET server_await_conn ( void )
 
     ERRLOG((stderr, "%s(%d): Listening at port %d\n", __FILE__, __LINE__, bindport));
 
-    if ((conn_sd = accept (listen_sd, &address, &address_len)) == INVALID_SOCKET) {
+    if ((conn_sd = accept (listen_sd, (struct sockaddr *)&address, &address_len)) == INVALID_SOCKET) {
 	print_errno ("conn_accept");
 	return INVALID_SOCKET;
     }
