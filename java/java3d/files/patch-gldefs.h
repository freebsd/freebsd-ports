--- j3d-core/src/native/ogl/gldefs.h.orig	2008-02-28 15:18:01.000000000 -0500
+++ j3d-core/src/native/ogl/gldefs.h	2015-02-20 17:51:50.420236000 -0500
@@ -65,6 +65,10 @@
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 
+#define GL_VERSION_1_5_TYPES_DEFINED
+typedef ptrdiff_t GLintptr;
+typedef ptrdiff_t GLsizeiptr;
+
 #include <GL/gl.h>
 #include <GL/glx.h>
 #ifdef Java3D_undef__glext_h_
