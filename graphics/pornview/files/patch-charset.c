--- src/support/charset.c.orig	Tue Nov 11 14:16:57 2008
+++ src/support/charset.c	Tue Nov 11 14:17:13 2008
@@ -468,7 +468,7 @@ charset_conv (const gchar * src,
 
 #ifdef USE_GTK2
     {
-	gint    rbytes, wbytes;
+	gsize    rbytes, wbytes;
 	return g_convert (src, -1, dest_codeset, src_codeset,
 			  &rbytes, &wbytes, NULL);
     }
