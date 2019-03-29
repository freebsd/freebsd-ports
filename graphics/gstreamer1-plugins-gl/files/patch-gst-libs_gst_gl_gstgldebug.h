--- gst-libs/gst/gl/gstgldebug.h.orig	2018-12-04 14:57:39 UTC
+++ gst-libs/gst/gl/gstgldebug.h
@@ -25,8 +25,6 @@
 
 G_BEGIN_DECLS
 
-typedef struct _GstGLAsyncDebug GstGLAsyncDebug;
-
 typedef gchar * (*GstGLAsyncDebugLogGetMessage) (gpointer user_data);
 
 /**
