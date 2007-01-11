--- ./src/xmms/nsf.h.orig	Sun Jul 23 12:00:35 2000
+++ ./src/xmms/nsf.h	Wed Jan 10 20:10:34 2007
@@ -58,7 +58,7 @@
 typedef struct
 {
 	gint play_time;
-	gint fadeout_time;
+	gint silence_time;
 	// reserve
 	gint resolution;
 	gint channels;
