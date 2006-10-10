--- src/x_menus.c.orig	Sun Aug  6 20:18:09 2006
+++ src/x_menus.c	Tue Oct 10 03:24:55 2006
@@ -241,7 +241,11 @@
 static gchar* gettext_fn(const gchar *path,
 			 gpointer func_data __attribute__((unused)))
 {
+#if defined(ENABLE_NLS)
 	return gettext(path);
+#else
+	return path;
+#endif
 }
 
 GtkWidget *get_main_popup(TOPLEVEL *w_current)
