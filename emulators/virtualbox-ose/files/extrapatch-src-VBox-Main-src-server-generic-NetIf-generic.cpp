--- src/VBox/Main/src-server/generic/NetIf-generic.cpp.orig	2013-08-21 13:05:31.000000000 +0400
+++ src/VBox/Main/src-server/generic/NetIf-generic.cpp	2013-08-27 18:17:51.598216723 +0400
@@ -22,6 +22,7 @@
 #include <iprt/path.h>
 #include <iprt/param.h>
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <net/if.h>
 #include <errno.h>
