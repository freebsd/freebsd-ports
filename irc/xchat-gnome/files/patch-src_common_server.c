--- src/common/server.c.orig	Sun Aug 10 17:40:15 2003
+++ src/common/server.c	Sat Oct 25 22:29:12 2003
@@ -289,8 +289,8 @@
 		{
 			char *conv_line; /* holds a copy of the original string */
 			int conv_len; /* tells g_convert how much of line to convert */
-			int utf_len;
-			int read_len;
+			gsize utf_len;
+			gsize read_len;
 			GError *err;
 			gboolean retry;
 
