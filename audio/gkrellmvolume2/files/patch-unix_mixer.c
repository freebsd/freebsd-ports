Index: unix_mixer.c
diff -u unix_mixer.c.orig unix_mixer.c
--- unix_mixer.c.orig	Tue Jun 17 04:03:16 2003
+++ unix_mixer.c	Sat Sep 27 12:51:20 2003
@@ -32,6 +32,9 @@
 #else
   #include <sys/soundcard.h>
 #endif
+#if defined(SOUND_MIXER_INFO) && defined(__FreeBSD__)
+#undef SOUND_MIXER_INFO
+#endif
 
 #include "mixer.h"
 #include "common_mixer.h"
