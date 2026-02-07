--- plugins/mp3/mp3.c.orig	2021-04-10 21:47:11 UTC
+++ plugins/mp3/mp3.c
@@ -22,7 +22,7 @@
 
 pthread_mutex_t dechandle_lock;
 
-struct mp3Handles{
+static struct mp3Handles{
 	mpg123_handle *m;
 	long total;
 	long tcarry;
