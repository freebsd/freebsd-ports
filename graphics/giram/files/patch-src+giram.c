--- src/giram.c.orig	Sun Dec 29 02:49:03 2002
+++ src/giram.c	Tue Oct 26 17:04:03 2004
@@ -26,6 +26,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
+#undef GTK_DISABLE_DEPRECATED
+#warning GTK_DISABLE_DEPRECATED
+
 #ifndef  WAIT_ANY
 #define  WAIT_ANY (-1)
 #endif   /*  WAIT_ANY  */
