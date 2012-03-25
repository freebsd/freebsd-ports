--- src/s_audio_alsa.c.orig	2011-11-07 13:06:38.000000000 +0900
+++ src/s_audio_alsa.c	2012-02-26 03:12:50.000000000 +0900
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
