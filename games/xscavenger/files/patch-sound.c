--- sound.c.orig	Tue May 22 17:45:42 2001
+++ sound.c	Tue May 22 17:45:53 2001
@@ -5,7 +5,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/time.h>
 #include <signal.h>
 #include <string.h>
