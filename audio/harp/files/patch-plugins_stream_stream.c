--- plugins/stream/stream.c.orig	2021-04-10 21:47:11 UTC
+++ plugins/stream/stream.c
@@ -23,7 +23,7 @@
 
 #define S_DEF_PORT_STR "80"
 
-struct streamHandles{
+static struct streamHandles{
 	FILE *rfd;
 	FILE *wfd;
 	int sfd;
