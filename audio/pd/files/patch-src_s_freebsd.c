$FreeBSD$

--- src/s_freebsd.c.orig	Sun Sep 28 15:48:40 2003
+++ src/s_freebsd.c	Sun Sep 28 15:48:41 2003
@@ -32,7 +32,8 @@
  * 1311:forum::für::umläute:2001
  */
 
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
+#include <sys/mman.h>
 
 #if (defined(ALSA01) || defined(ALSA99))
 #define ALSA
@@ -765,9 +766,11 @@
 #endif
 
 #ifdef _POSIX_MEMLOCK
+#if _POSIX_MEMLOCK != -1
     if (mlockall(MCL_FUTURE) != -1) 
     	fprintf(stderr, "memory locking enabled.\n");
 #endif
+#endif
 }
 
 /* ------------ linux-specific command-line flags -------------- */
@@ -868,7 +871,8 @@
     }
     else
     {
-    	wantformat = AFMT_S16_NE;
+/* FreeBSD's soundcard.h does not define AFMT_S16_NE */
+    	wantformat = AFMT_S16_BE;
 	dev->d_bytespersamp = 2;
     }
     param = wantformat;
@@ -2750,7 +2754,7 @@
 
   /* use ctrlpanel to change, experiment, channels 1 */
 
-  orig = param = AFMT_S16_NE;
+  orig = param = AFMT_S16_BE;
   if (ioctl(fd,SNDCTL_DSP_SETFMT,&param) == -1)
 	 fprintf(stderr,"RME9652: Could not set DSP format\n");
   else if( orig != param )
