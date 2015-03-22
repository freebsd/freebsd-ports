
$FreeBSD$

Fix build on FreeBSD 8
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198404#c6

--- mono/metadata/socket-io.c.orig
+++ mono/metadata/socket-io.c
@@ -23,6 +23,7 @@
 #ifdef HOST_WIN32
 #include <ws2tcpip.h>
 #else
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <netinet/in.h>
