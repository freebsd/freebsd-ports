--- src/lib/evas/Evas_GL.h.orig	2019-03-28 16:30:04 UTC
+++ src/lib/evas/Evas_GL.h
@@ -4272,9 +4272,11 @@ typedef signed int       GLfixed;      // Changed khro
 
 #ifndef GL_ES_VERSION_2_0
 /* GL types for handling large vertex buffer objects */
+#ifndef GL_VERSION_1_5
 #include <stddef.h>
 typedef ptrdiff_t GLintptr;     // Changed khronos_intptr_t
 typedef ptrdiff_t GLsizeiptr;   // Changed khronos_ssize_t
+#endif
 #endif
 
 /* Some definitions from GLES 3.0.
