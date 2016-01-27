Fix build on FreeBSD 8
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198404#c6

--- mono/metadata/socket-io.c.orig	2015-11-12 09:00:29 UTC
+++ mono/metadata/socket-io.c
@@ -26,6 +26,7 @@
 #ifdef HOST_WIN32
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #ifdef HAVE_SYS_IOCTL_H
 #include <sys/ioctl.h>
