--- src/s_freebsd.c.orig	Sun Oct 20 02:49:11 2002
+++ src/s_freebsd.c	Sun Oct 20 02:53:24 2002
@@ -32,7 +32,8 @@
  * 1311:forum::für::umläute:2001
  */
 
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
+#include <sys/mman.h>
 
 #if (defined(ALSA01) || defined(ALSA99))
 #define ALSA
@@ -865,7 +866,8 @@
     }
     else
     {
-    	wantformat = AFMT_S16_NE;
+/* FreeBSD's soundcard.h does not define AFMT_S16_NE */
+    	wantformat = AFMT_S16_BE;
 	dev->d_bytespersamp = 2;
     }
     param = wantformat;
@@ -2747,7 +2749,7 @@
 
   /* use ctrlpanel to change, experiment, channels 1 */
 
-  orig = param = AFMT_S16_NE;
+  orig = param = AFMT_S16_BE;
   if (ioctl(fd,SNDCTL_DSP_SETFMT,&param) == -1)
 	 fprintf(stderr,"RME9652: Could not set DSP format\n");
   else if( orig != param )
