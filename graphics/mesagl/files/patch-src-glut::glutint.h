
$FreeBSD$

--- src-glut/glutint.h	2003/05/01 18:41:40	1.1
+++ src-glut/glutint.h	2003/05/01 18:42:48
@@ -27,7 +27,7 @@
 #endif
 
 #define GLUT_BUILDING_LIB  /* Building the GLUT library itself. */
-#include <GL/glut.h>
+#include "../include/GL/glut.h"
 
 #if defined(MESA) && defined(_WIN32) && !defined(__CYGWIN32__)
 #include <gl/mesa_wgl.h>
