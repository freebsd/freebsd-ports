--- ./renderer/qgl.h.orig	Tue May 23 20:05:59 2006
+++ ./renderer/qgl.h	Tue May 23 20:06:00 2006
@@ -30,7 +30,7 @@
 
 #include <GL/gl.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#ifdef __unix__
 # include <GL/glx.h>
 #endif
 
@@ -431,7 +431,7 @@
 
 
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#ifdef __unix__
 
 //
 // linux
