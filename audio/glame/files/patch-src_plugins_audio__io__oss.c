--- src/plugins/audio_io_oss.c.orig	2005-03-27 12:29:48 UTC
+++ src/plugins/audio_io_oss.c
@@ -26,9 +26,9 @@
 
 #ifdef HAVE_OSS_LINUX
 #include <linux/soundcard.h>
-#elif HAVE_OSS_SYS
+#elif defined(HAVE_OSS_SYS)
 #include <sys/soundcard.h>
-#elif HAVE_OSS_MACHINE
+#elif defined(HAVE_OSS_MACHINE)
 #include <machine/soundcard.h>
 #else
 #error BUG in OSS configuration.
