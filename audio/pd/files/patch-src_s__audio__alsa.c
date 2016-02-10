--- src/s_audio_alsa.c.orig	2014-09-18 00:09:56 UTC
+++ src/s_audio_alsa.c
@@ -25,7 +25,14 @@
 #include <sched.h>
 #include <sys/mman.h>
 #include "s_audio_alsa.h"
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#define LITTLE_ENDIAN _LITTLE_ENDIAN
+#define BIG_ENDIAN _BIG_ENDIAN
+#define BYTE_ORDER _BYTE_ORDER
+#else
 #include <endian.h>
+#endif
 
 /* Defines */
 #define DEBUG(x) x
