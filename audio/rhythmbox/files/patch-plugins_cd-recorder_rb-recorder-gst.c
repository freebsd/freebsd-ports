--- plugins/cd-recorder/rb-recorder-gst.c.orig	Wed Aug 10 20:06:11 2005
+++ plugins/cd-recorder/rb-recorder-gst.c	Wed Aug 10 20:06:31 2005
@@ -25,7 +25,9 @@
 #include <string.h>
 #include <math.h>
 #include <time.h>
+#ifndef __FreeBSD__
 #include <sys/vfs.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
