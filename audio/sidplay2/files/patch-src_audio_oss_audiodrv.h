--- src/audio/oss/audiodrv.h.orig	2001-10-30 23:35:35 UTC
+++ src/audio/oss/audiodrv.h
@@ -57,15 +57,7 @@
 #include <stdio.h>
 #include <unistd.h>
 
-#if defined(HAVE_LINUX_SOUNDCARD_H)
-#   include <linux/soundcard.h>
-#elif defined(HAVE_MACHINE_SOUNDCARD_H)
-#   include <machine/soundcard.h>
-#elif defined(HAVE_SOUNDCARD_H)
-#   include <soundcard.h>
-#else
-#   error Audio driver not supported.
-#endif
+#include <sys/soundcard.h>
 
 #include "../AudioBase.h"
 
