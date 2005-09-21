--- glfont2.h.orig	Sat Dec 20 10:26:21 2003
+++ glfont2.h	Wed Sep 21 09:34:38 2005
@@ -8,7 +8,9 @@
 #ifndef GLFONT2_H
 #define GLFONT2_H
 
-//#include <pair.h>
+#if defined(__GNUC__) && (__GNUC__ < 3)
+#include <pair.h>
+#endif
 #include <string>
 #include <GL/gl.h>
 #include <GL/glu.h>
