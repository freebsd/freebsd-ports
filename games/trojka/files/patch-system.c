--- system.c.orig	Sat Oct 21 05:16:20 1995
+++ system.c	Mon Jul 17 21:09:48 2000
@@ -23,6 +23,9 @@
 #include <stdio.h>
 #include <time.h>
 #include <fcntl.h>
+#ifdef __FreeBSD__
+#include <sys/ioctl.h>
+#endif
 
 #include "trojka.h"
 
@@ -42,7 +45,7 @@
 
 char getkey()			/* get key from keyboard	*/
 {
-#if SUNOS | HPUX | LINUX
+#if SUNOS | HPUX | LINUX | __FreeBSD__
 	long count;
 	char ch;
 
@@ -119,7 +122,7 @@
 int delay(millisecs)
 int millisecs;
 {
-#if SUNOS | LINUX
+#if SUNOS | LINUX | __FreeBSD__
 	usleep(millisecs * 1200);	/* usleep does microsecs; need millisecs */
 #endif
 #ifdef HPUX
