--- tcap.c.orig	Sat Dec 13 17:34:59 1997
+++ tcap.c	Thu Mar 21 03:53:02 2002
@@ -39,7 +39,7 @@
 
 #ifdef BSD
 #include <sys/ioctl.h>
-struct winsize ttysize;
+struct ttysize ttysize;
 #endif /* BSD */
 #ifdef ULTRIX
 struct winsize ttysize;
