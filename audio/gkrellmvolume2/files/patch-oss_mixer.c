Index: oss_mixer.c
diff -u -p oss_mixer.c.orig oss_mixer.c
--- oss_mixer.c.orig	Wed May 19 04:39:27 2004
+++ oss_mixer.c	Wed May 19 04:39:43 2004
@@ -32,6 +32,9 @@
 #else
   #include <sys/soundcard.h>
 #endif
+#if defined(SOUND_MIXER_INFO) && defined(__FreeBSD__)
+#undef SOUND_MIXER_INFO
+#endif
 
 #include "mixer.h"
 #include "oss_mixer.h"
