Clang compatibility
--- src/gui_materials.c.orig	2006-01-22 09:37:31 UTC
+++ src/gui_materials.c
@@ -66,7 +66,7 @@ static gboolean kudu_gui_materials_edit_
 	return TRUE;
 }
 
-int kudu_gui_materials_edit_init(GtkWidget *widget, gpointer data)
+void kudu_gui_materials_edit_init(GtkWidget *widget, gpointer data)
 {
 	GdkGLContext *glContext = gtk_widget_get_gl_context(widget);
 	GdkGLDrawable *glDrawable = gtk_widget_get_gl_drawable(widget);
