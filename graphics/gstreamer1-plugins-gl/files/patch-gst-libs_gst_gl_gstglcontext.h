--- gst-libs/gst/gl/gstglcontext.h.orig	2018-12-05 14:06:09 UTC
+++ gst-libs/gst/gl/gstglcontext.h
@@ -98,7 +98,7 @@ struct _GstGLContext {
   GstGLWindow  *window;
 
   /*< public >*/
-  GstGLFuncs *gl_vtable;
+  struct _GstGLFuncs *gl_vtable;
 
   /*< private >*/
   GstGLContextPrivate *priv;
