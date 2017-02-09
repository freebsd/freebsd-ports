--- SID_linux.i.orig	2002-01-02 21:17:00 UTC
+++ SID_linux.i
@@ -8,7 +8,12 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+
+#if defined(__linux__)
+#  include <linux/soundcard.h>
+#elif defined(__FreeBSD__)
+#  include <sys/soundcard.h>
+#endif
 
 #include "VIC.h"
 
