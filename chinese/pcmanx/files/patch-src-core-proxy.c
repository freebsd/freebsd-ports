--- src/core/proxy.c.orig	2011-12-28 19:59:03.000000000 +0800
+++ src/core/proxy.c	2012-05-01 10:42:46.000000000 +0800
@@ -22,6 +22,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <errno.h>
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
 
 #include "proxy.h"
 
