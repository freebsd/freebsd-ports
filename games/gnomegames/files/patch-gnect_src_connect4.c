--- gnect/src/connect4.c.orig	Sun May 26 21:23:34 2002
+++ gnect/src/connect4.c	Sun May 26 21:26:30 2002
@@ -117,7 +117,7 @@
 	long size,len;
 	FILE *h1;
 	short x;
-	char *bookdata = g_strdup("/usr/share/gnect/" WHITE_BOOK); /* FIXME */
+	char *bookdata = g_strdup(GNECT_DATA_DIR "/gnect/" WHITE_BOOK); /* FIXME */
 
 
 	if (!gnect_file_exists(bookdata)) {
