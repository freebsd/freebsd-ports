--- src/platform/LinuxMedia.cxx.orig	Sat Aug 12 00:50:20 2000
+++ src/platform/LinuxMedia.cxx	Sat Aug 12 00:53:05 2000
@@ -13,9 +13,13 @@
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
@@ -23,6 +27,9 @@
 #include <sys/ioctl.h>
 #include <TimeKeeper.h>
 #include <errno.h>
+#if defined(BSD)
+#include <string.h>
+#endif
 
 #ifdef HALF_RATE_AUDIO
 static const int defaultAudioRate=11025;
