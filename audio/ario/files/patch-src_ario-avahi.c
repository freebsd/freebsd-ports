--- src/ario-avahi.c.orig	2011-07-18 20:05:50.915461042 +0200
+++ src/ario-avahi.c	2011-07-18 20:08:56.334574365 +0200
@@ -34,6 +34,11 @@
 #include <avahi-common/simple-watch.h>
 #include "ario-debug.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#include <netinet/in.h>
+#endif
+
 #define SERVICE_TYPE "_mpd._tcp"
 #define DOMAIN "local"
 
