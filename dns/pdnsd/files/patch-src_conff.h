--- src/conff.h.orig	Fri Oct 29 01:11:36 2004
+++ src/conff.h	Fri Oct 29 01:12:36 2004
@@ -32,6 +32,9 @@
 #include <config.h>
 #include <stdio.h>
 #include <pthread.h>
+#if TARGET==TARGET_BSD
+#include <sys/socket.h>
+#endif
 #include <net/if.h>
 #include "ipvers.h"
 #include "list.h"
