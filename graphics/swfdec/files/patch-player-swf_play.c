--- player/swf_play.c.orig	Thu Apr  3 23:11:57 2003
+++ player/swf_play.c	Fri Apr  2 13:34:32 2004
@@ -390,7 +390,7 @@
 static gboolean input(GIOChannel *chan, GIOCondition cond, gpointer ignored)
 {
 	char *data;
-	int bytes_read;
+	gsize bytes_read;
 	GError *error = NULL;
 	int ret;
 
