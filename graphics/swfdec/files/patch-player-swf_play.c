--- player/swf_play.c.orig	Mon Mar 29 11:43:50 2004
+++ player/swf_play.c	Mon Mar 29 11:44:14 2004
@@ -390,7 +390,7 @@
 static gboolean input(GIOChannel *chan, GIOCondition cond, gpointer ignored)
 {
 	char *data;
-	int bytes_read;
+	long bytes_read;
 	GError *error = NULL;
 	int ret;
 
