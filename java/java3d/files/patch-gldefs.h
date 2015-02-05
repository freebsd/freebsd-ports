--- j3d-core/src/native/ogl/gldefs.h.orig	2008-02-28 15:18:01.000000000 -0500
+++ j3d-core/src/native/ogl/gldefs.h	2015-02-05 16:38:10.813942000 -0500
@@ -65,6 +65,8 @@
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 
+typedef ptrdiff_t GLsizeiptr;
+typedef ptrdiff_t GLintptr;
 #include <GL/gl.h>
 #include <GL/glx.h>
 #ifdef Java3D_undef__glext_h_
