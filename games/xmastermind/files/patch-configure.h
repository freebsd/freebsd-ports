--- configure.h.orig	Mon Jul  1 02:27:59 2002
+++ configure.h	Mon Jul  1 02:27:19 2002
@@ -4,8 +4,10 @@
 #define VERSION 0.1 
 
 /* some stuff */
+#ifndef TRUE
 #define TRUE 1
 #define FALSE 0
+#endif
 #define BOOLEAN int
 
 /* Don't change this, because it will not work right with the GUI. Sorry! */
