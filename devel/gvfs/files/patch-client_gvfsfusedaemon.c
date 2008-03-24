--- client/gvfsfusedaemon.c.orig	2007-11-06 18:06:41.000000000 -0500
+++ client/gvfsfusedaemon.c	2007-11-06 18:07:30.000000000 -0500
@@ -28,7 +28,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#ifdef __linux__
 #include <sys/vfs.h>
+#endif
 #include <sys/time.h>
 #include <unistd.h>
 #include <stdlib.h>
