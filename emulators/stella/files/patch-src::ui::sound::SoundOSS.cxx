--- src/ui/sound/SoundOSS.cxx.orig	Tue Feb 18 10:19:44 2003
+++ src/ui/sound/SoundOSS.cxx	Tue Sep 16 20:10:20 2003
@@ -22,11 +22,7 @@
 #include <sys/ioctl.h>
 #include <sys/types.h>
 
-#ifdef __FreeBSD__
-  #include <machine/soundcard.h>
-#else
-  #include <sys/soundcard.h>
-#endif
+#include <sys/soundcard.h>
 
 #define DSP_DEVICE "/dev/dsp"
 #define MIXER_DEVICE "/dev/mixer"
