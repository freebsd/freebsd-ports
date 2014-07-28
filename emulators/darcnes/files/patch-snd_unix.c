--- snd_unix.c.orig	Wed Oct 23 20:11:53 2002
+++ snd_unix.c	Wed Oct 23 20:12:07 2002
@@ -23,7 +23,7 @@
 #endif
 
 #ifdef SYSTEM_FREEBSD
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #define SOUND_DEVICE "/dev/dsp"
 #endif
 
