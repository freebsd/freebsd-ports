--- ./include/qgl_local.h.orig	Mon Dec 25 17:07:02 2006
+++ ./include/qgl_local.h	Mon Dec 25 17:07:02 2006
@@ -3,7 +3,7 @@
 #include <windows.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
-#elif (defined __linux__)
+#elif (defined __unix__)
 #include <GL/gl.h>
 #else
 #error Unknown Target OS
