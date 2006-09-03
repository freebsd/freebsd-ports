--- ./gl/gl_vidlinuxglx.c.orig	Tue Jul 18 00:34:46 2006
+++ ./gl/gl_vidlinuxglx.c	Sat Sep  2 18:40:11 2006
@@ -41,7 +41,7 @@
 #include <X11/extensions/xf86dga.h>
 #endif
 
-#ifdef __linux__
+#ifdef __unix__
 	#define WITH_VMODE	//undefine this if the following include fails.
 #endif
 #ifdef WITH_VMODE
