--- src/minicom.h.orig	2008-04-17 20:06:14.000000000 +0200
+++ src/minicom.h	2008-04-17 20:06:22.000000000 +0200
@@ -34,6 +34,7 @@
 #include "libport.h"
 
 #include <time.h>
+#include <limits.h>
 
 #ifdef USE_SOCKET
 #include <sys/socket.h>
