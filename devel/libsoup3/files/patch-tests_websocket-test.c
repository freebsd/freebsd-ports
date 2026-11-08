--- tests/websocket-test.c.orig	2026-09-13 22:26:00 UTC
+++ tests/websocket-test.c
@@ -28,6 +28,10 @@
 #include <sys/socket.h>
 #endif
 
+#ifndef MAP_NORESERVE
+#define MAP_NORESERVE 0
+#endif
+
 typedef struct {
 	GSocket *listener;
 	gushort port;
