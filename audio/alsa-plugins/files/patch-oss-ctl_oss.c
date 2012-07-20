--- oss/ctl_oss.c.orig	2008-10-29 08:42:13.000000000 -0400
+++ oss/ctl_oss.c
@@ -26,7 +26,11 @@
 #include <sys/ioctl.h>
 #include <alsa/asoundlib.h>
 #include <alsa/control_external.h>
+#ifdef __linux__
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 
 typedef struct snd_ctl_oss {
 	snd_ctl_ext_t ext;
