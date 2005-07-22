--- src/glarea.c.orig	Wed Jul 13 05:18:12 2005
+++ src/glarea.c	Wed Jul 20 02:34:25 2005
@@ -55,6 +55,7 @@
 #ifdef HAVE_GTKGLEXT
 	GdkGLDrawable *gldrawable;
 	GdkGLContext *glcontext;
+	G3DModel *model;
 
 	gldrawable = gtk_widget_get_gl_drawable(widget);
 	glcontext = gtk_widget_get_gl_context(widget);
@@ -64,7 +65,7 @@
 	if(gtk_gl_area_make_current(GTK_GL_AREA(widget)))
 	{
 #endif
-		G3DModel *model = (G3DModel*)gtk_object_get_data(GTK_OBJECT(widget),
+		model = (G3DModel*)gtk_object_get_data(GTK_OBJECT(widget),
 			"model");
 		glViewport(0,0, widget->allocation.width, widget->allocation.height);
 		model->aspect = (float)widget->allocation.width /
