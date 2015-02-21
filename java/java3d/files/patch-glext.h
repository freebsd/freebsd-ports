--- j3d-core/src/native/ogl/glext.h.orig	2007-02-26 13:37:09.000000000 -0500
+++ j3d-core/src/native/ogl/glext.h	2015-02-20 17:50:53.517494000 -0500
@@ -3389,10 +3389,12 @@
 #endif
 
 #ifndef GL_VERSION_1_5
+#ifndef GL_VERSION_1_5_TYPES_DEFINED
 /* GL types for handling large vertex buffer objects */
 typedef ptrdiff_t GLintptr;
 typedef ptrdiff_t GLsizeiptr;
 #endif
+#endif
 
 #ifndef GL_ARB_vertex_buffer_object
 /* GL types for handling large vertex buffer objects */
