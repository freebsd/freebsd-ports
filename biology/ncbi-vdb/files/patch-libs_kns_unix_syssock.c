--- libs/kns/unix/syssock.c.orig	2017-07-14 21:55:36 UTC
+++ libs/kns/unix/syssock.c
@@ -66,6 +66,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
