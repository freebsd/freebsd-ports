--- radio.c.orig	2001-11-27 21:30:42 UTC
+++ radio.c
@@ -63,17 +63,17 @@
 #ifdef __NetBSD__
 #include <dev/ic/bt8xx.h>
 #include <soundcard.h>
-#else
-#ifdef linux
+#elif defined(linux)
 #include <linux/bttv.h>
 #include <sys/soundcard.h>
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#include <dev/bktr/ioctl_bt848.h>
 #else
-#include <machine/ioctl_bt848.h>
-#ifdef JUHA_DRIVER
-#include <machine/ioctl_tuner.h>
-#endif
 #include <machine/soundcard.h>
 #endif
+#ifdef JUHA_DRIVER
+#include <machine/ioctl_tuner.h>
 #endif
 
 #include <X11/X.h>
