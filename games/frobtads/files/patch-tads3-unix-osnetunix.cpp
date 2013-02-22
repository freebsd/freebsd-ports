--- tads3/unix/osnetunix.cpp.orig	2012-08-21 22:35:14.000000000 +0200
+++ tads3/unix/osnetunix.cpp	2013-02-22 10:30:06.000000000 +0100
@@ -15,6 +15,7 @@
 #include <poll.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <sys/ioctl.h>
 #include <sys/times.h>
