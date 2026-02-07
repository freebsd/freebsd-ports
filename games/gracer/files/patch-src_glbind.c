--- src/glbind.c.orig	Mon Mar 10 15:31:50 2003
+++ src/glbind.c	Mon Mar 10 15:31:52 2003
@@ -20,6 +20,7 @@
  */
 
 #include <unistd.h>
+#define GL_GLEXT_LEGACY
 #include <GL/gl.h>
 #include <GL/glut.h>
 #include <string.h>
