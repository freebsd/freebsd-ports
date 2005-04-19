--- src/main.c.orig	Tue Oct 19 07:37:18 2004
+++ src/main.c	Tue Apr 19 00:37:09 2005
@@ -17,8 +17,9 @@
 get_filename()
 {
 	gchar buf[50];
+	gchar* file;
 	g_sprintf (buf, "%s/.rgb.txt", getenv ("HOME"));
-	gchar* file = g_strdup (buf);
+	file = g_strdup (buf);
 	return file;
 }
 
@@ -48,10 +49,11 @@
 		"................"
 	};
 	gchar colorline[] = ".      c #FFFFFF";
+	GdkPixbuf *buf;
 	
 	g_sprintf (colorline, ".      c %s", g_ascii_strup (spec, -1));
 	swatchxpm[1] = colorline;
-	GdkPixbuf *buf = gdk_pixbuf_new_from_xpm_data ((gchar const **)swatchxpm);
+	buf = gdk_pixbuf_new_from_xpm_data ((gchar const **)swatchxpm);
 
 	if (is_top)
 		gtk_list_store_prepend (liststore, &iter);
