--- src/mixer.h.orig	Sat Jul 24 13:16:52 2004
+++ src/mixer.h	Sat Jul 24 13:17:30 2004
@@ -23,7 +23,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <stdio.h>
