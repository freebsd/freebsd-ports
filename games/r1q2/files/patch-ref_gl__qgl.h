--- ./ref_gl/qgl.h.orig	Wed May 17 22:21:33 2006
+++ ./ref_gl/qgl.h	Wed May 17 22:29:57 2006
@@ -436,7 +436,7 @@
 
 #endif
 
-#ifdef __linux__
+#ifdef __unix__
 
 // local function in dll
 extern void *qwglGetProcAddress(char *symbol);
