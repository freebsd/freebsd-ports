--- src/platform/LinuxMedia.cxx.orig	Sat Jan 15 04:09:48 2000
+++ src/platform/LinuxMedia.cxx	Fri Aug 18 16:44:02 2000
@@ -13,16 +13,27 @@
 #include "LinuxMedia.h"
 #include <math.h>
 #include <fcntl.h>
+#include <sys/param.h>
+#if !defined(BSD)
 #include <endian.h>
+#else
+#include <machine/endian.h>
+#endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <signal.h>
+#if !defined(BSD)
 #include <sys/soundcard.h>
+#else
+#include <machine/soundcard.h>
+#endif
 #include <sys/ioctl.h>
 #include <TimeKeeper.h>
 #include <errno.h>
+#if defined(BSD)
+#include <string.h>
+#endif
 
 #ifdef HALF_RATE_AUDIO
 static const int defaultAudioRate=11025;
