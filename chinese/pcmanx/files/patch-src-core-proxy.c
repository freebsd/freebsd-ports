--- src/core/proxy.c.orig	2011-12-28 19:59:03.000000000 +0800
+++ src/core/proxy.c	2012-05-01 10:42:46.000000000 +0800
@@ -23,6 +23,8 @@
 #include <unistd.h>
 #include <errno.h>
 
+#include <sys/socket.h>
+
 #include "proxy.h"
 
 #define SOCKS_CMD_CONNECT        0x01
