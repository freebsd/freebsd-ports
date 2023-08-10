--- ncbi-vdb/libs/kns/unix/syssock.c.orig	2023-08-07 20:34:54 UTC
+++ ncbi-vdb/libs/kns/unix/syssock.c
@@ -66,6 +66,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
