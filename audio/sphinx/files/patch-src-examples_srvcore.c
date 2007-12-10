--- src/examples/srvcore.c.orig	2007-12-06 18:35:25.000000000 +0100
+++ src/examples/srvcore.c	2007-12-06 18:35:56.000000000 +0100
@@ -381,7 +381,7 @@
 
     ERRLOG((stderr, "%s(%d): Listening at port %d\n", __FILE__, __LINE__, bindport));
 
-    if ((conn_sd = accept (listen_sd, &address, &address_len)) == INVALID_SOCKET) {
+    if ((conn_sd = accept (listen_sd, (struct sockaddr *)&address, &address_len)) == INVALID_SOCKET) {
 	print_errno ("conn_accept");
 	return INVALID_SOCKET;
     }
