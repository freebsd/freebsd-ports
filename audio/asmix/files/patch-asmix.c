--- asmix.c.orig	Sun Aug 31 15:18:35 2003
+++ asmix.c	Sun Aug 31 15:19:04 2003
@@ -22,9 +22,7 @@
 #include <sys/errno.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#ifdef HAVE_MACHINE_SOUNDCARD_H
-#  include <machine/soundcard.h>
-#endif
+#include <sys/soundcard.h>
 #ifdef HAVE_LINUX_SOUNDCARD_H
 #  include <linux/soundcard.h>
 #endif
