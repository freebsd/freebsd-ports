--- src/VBox/Devices/Network/slirp/resolv_conf_parser.c.orig	2014-01-30 22:19:47.429683181 +0400
+++ src/VBox/Devices/Network/slirp/resolv_conf_parser.c	2014-01-30 22:22:08.149672985 +0400
@@ -15,6 +15,8 @@
  * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
  */
 
+#include <sys/socket.h>
+
 #include <iprt/assert.h>
 #include <iprt/initterm.h>
 #include <iprt/net.h>
