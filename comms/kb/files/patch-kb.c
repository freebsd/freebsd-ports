--- kb.c.orig	2007-09-10 14:58:04.000000000 -0400
+++ kb.c	2007-11-24 14:46:35.000000000 -0500
@@ -1,7 +1,12 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#ifndef BSD
 #include <sys/io.h>
+#endif
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
@@ -3090,10 +3095,14 @@
 
   gtk_key_snooper_install (kp_snooper, drawing_area);
 
+#ifdef __FreeBSD__
+  fd_bells = open("/dev/speaker", O_RDWR);
+#else
   fd_bells = open("/dev/kb_bells", O_RDWR);
+#endif
   g_thread_init (NULL);
   gtk_main ();
-  close(fd_bells);
-
+  if(fd_bells > 0)
+    close(fd_bells);
   return 0;
 }
