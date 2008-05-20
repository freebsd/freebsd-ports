--- mupen64_audio/main.c	2007-10-08 01:41:12.000000000 -0500
+++ mupen64_audio/main.c	2007-10-08 01:41:23.000000000 -0500
@@ -6,7 +6,7 @@
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <unistd.h>
 #include <pthread.h>
 #include <sys/time.h>
