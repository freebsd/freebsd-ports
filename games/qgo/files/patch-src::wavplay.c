--- src/wavplay.c.orig	Sun Oct 31 08:35:00 2004
+++ src/wavplay.c	Tue Dec 14 19:32:31 2004
@@ -54,19 +54,26 @@
  *
  */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 static const char rcsid[] = "@(#)recplay.c $Revision: 1.8 $";
 
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
+#if defined(__linux__)
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/stat.h>
+#if defined(__linux__)
 #include <linux/soundcard.h>
+#endif
+#if defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 /*/#include "server.h"*/
 
