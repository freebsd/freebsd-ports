--- radio.c.orig	Tue Nov 27 13:30:42 2001
+++ radio.c	Sun Sep  8 03:13:58 2002
@@ -63,17 +63,17 @@
 #ifdef __NetBSD__
 #include <dev/ic/bt8xx.h>
 #include <soundcard.h>
-#else
-#ifdef linux
+#elif defined(linux)
 #include <linux/bttv.h>
 #include <sys/soundcard.h>
-#else
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
 #include <machine/ioctl_bt848.h>
-#ifdef JUHA_DRIVER
-#include <machine/ioctl_tuner.h>
-#endif
+#else
 #include <machine/soundcard.h>
 #endif
+#ifdef JUHA_DRIVER
+#include <machine/ioctl_tuner.h>
 #endif
 
 #include <X11/X.h>
