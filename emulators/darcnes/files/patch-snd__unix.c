--- snd_unix.c.orig	2000-10-30 22:18:27 UTC
+++ snd_unix.c
@@ -23,7 +23,7 @@
 #endif
 
 #ifdef SYSTEM_FREEBSD
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #define SOUND_DEVICE "/dev/dsp"
 #endif
 
