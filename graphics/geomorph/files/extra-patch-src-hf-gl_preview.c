--- src/hf/gl_preview.c.orig	Wed Nov 23 06:44:22 2005
+++ src/hf/gl_preview.c	Mon Mar  6 12:59:24 2006
@@ -337,10 +337,10 @@
 // printf ("Realize Event\n");
 
   	gl_preview_struct *gl_hf;
-  	gl_hf = ((hf_wrapper_struct *) data)->gl_preview;
 
 	GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
 	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);
+  	gl_hf = ((hf_wrapper_struct *) data)->gl_preview;
 
   /*** OpenGL BEGIN ***/
 	if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext)) {
@@ -588,6 +588,8 @@
 	gint i;
 	camera_struct *camera;
 	gl_preview_struct *gl_hf;
+	GdkGLContext *glcontext;
+	GdkGLDrawable *gldrawable;
 	gl_hf = ((hf_wrapper_struct *) data)->gl_preview;
 	camera = gl_hf->cameras[gl_hf->current_camera_id];
   /* Draw only on the last expose event. */
@@ -600,8 +602,8 @@
 
 //	printf("************* GL DRAWING 2 ************** - HFW: %d\n", data);
   
-  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
-  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);
+  glcontext = gtk_widget_get_gl_context (widget);
+  gldrawable = gtk_widget_get_gl_drawable (widget);
 
   /*** OpenGL BEGIN ***/
   if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
