--- src/MainGLUT.cpp.orig	2008-03-15 13:42:48.000000000 +0300
+++ src/MainGLUT.cpp	2008-07-11 00:45:02.000000000 +0400
@@ -5,6 +5,10 @@
  * it and/or use it and/or modify it under the terms of the 
  * "Artistic License" 
  */
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include "MainGLUT.h"
 
 #ifdef USE_GLUT
