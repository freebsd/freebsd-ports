Clang compatibility
--- src/gui_materials.c.orig	2006-01-22 12:37:31.000000000 +0300
+++ src/gui_materials.c	2013-06-13 20:40:43.037204137 +0400
@@ -66,7 +66,7 @@
 	return TRUE;
 }
 
-int kudu_gui_materials_edit_init(GtkWidget *widget, gpointer data)
+void kudu_gui_materials_edit_init(GtkWidget *widget, gpointer data)
 {
 	GdkGLContext *glContext = gtk_widget_get_gl_context(widget);
 	GdkGLDrawable *glDrawable = gtk_widget_get_gl_drawable(widget);
