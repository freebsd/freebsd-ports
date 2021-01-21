client.c:210:18: error: use of undeclared identifier 'IPPROTO_TCP'
        setsockopt(cfd, IPPROTO_TCP, TCP_NODELAY, (void*)&yes, sizeof(int));

--- src/client.c.orig	2020-06-09 16:20:07 UTC
+++ src/client.c
@@ -31,6 +31,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/un.h>
 #include <arpa/inet.h>
