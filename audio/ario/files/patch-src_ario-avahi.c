--- src/ario-avahi.c.orig	2018-04-04 12:36:02 UTC
+++ src/ario-avahi.c
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
 
