$FreeBSD$

--- src/s_freebsd.c.orig	Fri May 23 00:52:34 2003
+++ src/s_freebsd.c	Fri May 23 01:01:59 2003
@@ -32,7 +32,8 @@
  * 1311:forum::für::umläute:2001
  */
 
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
+#include <sys/mman.h>
 
 #if (defined(ALSA01) || defined(ALSA99))
 #define ALSA
@@ -762,8 +762,10 @@
 #endif
 
 #ifdef _POSIX_MEMLOCK
+#if _POSIX_MEMLOCK != -1
     if (mlockall(MCL_FUTURE) != -1) 
     	fprintf(stderr, "memory locking enabled.\n");
+#endif
 #endif
 }
 
@@ -865,7 +868,8 @@
     }
     else
     {
-    	wantformat = AFMT_S16_NE;
+/* FreeBSD's soundcard.h does not define AFMT_S16_NE */
+    	wantformat = AFMT_S16_BE;
 	dev->d_bytespersamp = 2;
     }
     param = wantformat;
@@ -2747,7 +2751,7 @@
 
   /* use ctrlpanel to change, experiment, channels 1 */
 
-  orig = param = AFMT_S16_NE;
+  orig = param = AFMT_S16_BE;
   if (ioctl(fd,SNDCTL_DSP_SETFMT,&param) == -1)
 	 fprintf(stderr,"RME9652: Could not set DSP format\n");
   else if( orig != param )
