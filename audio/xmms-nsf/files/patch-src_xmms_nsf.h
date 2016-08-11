--- src/xmms/nsf.h.orig	2000-07-23 10:00:35 UTC
+++ src/xmms/nsf.h
@@ -58,7 +58,7 @@ NsfFile;
 typedef struct
 {
 	gint play_time;
-	gint fadeout_time;
+	gint silence_time;
 	// reserve
 	gint resolution;
 	gint channels;
