$FreeBSD$

--- sndstretch_xmms.c.orig	Thu Sep 27 17:32:50 2001
+++ sndstretch_xmms.c	Sat Nov 10 12:54:24 2001
@@ -27,7 +27,11 @@
 #include "sndstretch.h"
 #include <fcntl.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <linux/soundcard.h>
+#endif
 #include <unistd.h>
 #include <math.h>
 #include <stdlib.h>
