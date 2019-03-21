--- overlay_gl/overlay.c.orig	2019-03-13 18:38:10 UTC
+++ overlay_gl/overlay.c
@@ -16,6 +16,7 @@
 #include <sys/ipc.h>
 #include <sys/time.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <sys/un.h>
 #include <sys/stat.h>
 #include <time.h>
