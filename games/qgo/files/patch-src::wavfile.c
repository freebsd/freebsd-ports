--- src/wavfile.c.orig	Sun Oct 31 08:36:45 2004
+++ src/wavfile.c	Thu Dec 16 01:18:54 2004
@@ -41,7 +41,7 @@
  *	wavplay project.
  */	
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 static const char rcsid[] = "@(#)wavfile.c $Revision: 1.6 $";
 
@@ -52,7 +52,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <fcntl.h>
+#if defined(__linux__)
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <memory.h>
 #include <signal.h>
@@ -60,7 +62,12 @@
 #include <sys/ipc.h>
 #include <sys/ioctl.h>
 #include <assert.h>
+#if defined(__linux__)
 #include <linux/soundcard.h>
+#endif
+#if defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#endif
 
 
 
