--- oss_mixer.c.orig	2004-08-20 00:07:27.000000000 +0400
+++ oss_mixer.c	2015-02-01 20:21:32.000000000 +0300
@@ -32,6 +32,9 @@
 #else
   #include <sys/soundcard.h>
 #endif
+#if defined(SOUND_MIXER_INFO) && defined(__FreeBSD__)
+#undef SOUND_MIXER_INFO
+#endif
 
 #include "mixer.h"
 #include "oss_mixer.h"
@@ -126,7 +129,7 @@
   long amount;
   ioctl(OSSMIXER(mixer)->fd,MIXER_READ(OSSMIXER(mixer)->table[devid]),&amount);
   *left = amount & 0xff;
-  *right = amount >> 8;
+  *right = (amount >> 8) & 0xff;
 }
 
 static void  
