--- src/conff.h.orig	Mon Jun 27 21:57:22 2005
+++ src/conff.h		Sun Oct 30 09:01:08 2005
@@ -32,6 +32,9 @@
 #include <config.h>
 #include <stdio.h>
 #include <pthread.h>
+#if TARGET==TARGET_BSD
+#include <sys/socket.h>
+#endif
 #include <sys/socket.h>
 #include <net/if.h>
 #include "ipvers.h"
