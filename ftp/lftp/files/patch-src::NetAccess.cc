--- src/NetAccess.cc.orig	Wed Jan  8 16:56:22 2003
+++ src/NetAccess.cc	Wed Jan  8 16:56:41 2003
@@ -25,6 +25,7 @@
 #include <errno.h>
 #include <assert.h>
 #include <math.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include "NetAccess.h"
