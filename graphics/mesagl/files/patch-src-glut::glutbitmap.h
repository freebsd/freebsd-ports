
$FreeBSD$

--- src-glut/glutbitmap.h	2003/05/01 18:41:40	1.1
+++ src-glut/glutbitmap.h	2003/05/01 18:42:58
@@ -9,7 +9,7 @@
 
 #define GLUT_NO_LIB_PRAGMA  /* Avoid auto library linking when building
                                the GLUT library itself. */
-#include <GL/glut.h>
+#include "../include/GL/glut.h"
 
 typedef struct {
   const GLsizei width;
