--- portaudio/src/hostapi/oss/pa_unix_oss.c.orig	2021-04-18 05:58:24 UTC
+++ portaudio/src/hostapi/oss/pa_unix_oss.c
@@ -71,7 +71,7 @@
 #  define DEVICE_NAME_BASE           "/dev/dsp"
 # endif
 #elif defined(HAVE_LINUX_SOUNDCARD_H)
-# include <linux/soundcard.h>
+# include <sys/soundcard.h>
 # define DEVICE_NAME_BASE            "/dev/dsp"
 #elif defined(HAVE_MACHINE_SOUNDCARD_H)
 # include <machine/soundcard.h> /* JH20010905 */
