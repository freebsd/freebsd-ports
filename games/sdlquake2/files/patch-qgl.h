--- ./qgl.h.orig	Thu May 19 17:56:13 2005
+++ ./qgl.h	Sun Feb 26 11:23:56 2006
@@ -31,7 +31,7 @@
 #include <GL/gl.h>
 #include "glext.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 //#include <GL/fxmesa.h>
 #include <GL/glx.h>
 #endif
@@ -436,7 +436,7 @@
 
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 // local function in dll
 extern void *qwglGetProcAddress(char *symbol);
