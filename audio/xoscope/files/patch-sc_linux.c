--- sc_linux.c.orig	2005-06-28 17:34:50.000000000 -0400
+++ sc_linux.c	2008-07-26 19:20:00.000000000 -0400
@@ -21,6 +21,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 #include <fcntl.h>
 #include <errno.h>
 #include <stdlib.h>		/* for abs() */
@@ -91,6 +94,9 @@
 static void
 check_status_ioctl(int d, int request, void *argp, int line)
 {
+  if (d < 0) {
+    return;
+  }
   if (ioctl(d, request, argp) < 0) {
     snd_errormsg1 = "sound ioctl";
     snd_errormsg2 = strerror(errno);
@@ -169,8 +175,10 @@
     return 0;
   }
 
+#ifndef BSD
   parm = dma;			/* set DMA buffer size */
   check_status_ioctl(snd, SOUND_PCM_SUBDIVIDE, &parm, __LINE__);
+#endif
 
   parm = chan;			/* set mono/stereo */
   //check_status_ioctl(snd, SOUND_PCM_WRITE_CHANNELS, &parm, __LINE__);
