--- polyp/socket-util.c.orig	Fri Oct 29 16:48:42 2004
+++ polyp/socket-util.c	Fri Oct 29 17:04:57 2004
@@ -30,13 +30,16 @@
 #include <assert.h>
 #include <string.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/un.h>
 #include <netinet/in.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/types.h>
+#include <netinet/in_systm.h>
 #include <netinet/tcp.h>
 #include <netinet/ip.h>
+#include <sys/socket.h>
+#include <sys/stat.h>
 #include <netdb.h>
 
 #include "socket-util.h"
@@ -94,9 +97,11 @@
     int priority;
     assert(fd >= 0);
 
+#ifdef SO_PRIORITY
     priority = 7;
     if (setsockopt(fd, SOL_SOCKET, SO_PRIORITY, &priority, sizeof(priority)) < 0)
         return -1;
+#endif
 
     return 0;
 }
@@ -109,12 +114,25 @@
     ret = pa_socket_low_delay(fd);
     
     on = 1;
+#if defined(SOL_TCP) || defined(IPPROTO_TCP)
+#if defined(SOL_TCP)
     if (setsockopt(fd, SOL_TCP, TCP_NODELAY, &on, sizeof(on)) < 0)
+#else
+    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on)) < 0)
+#endif
         ret = -1;
+#endif
 
+#if defined(IPTOS_LOWDELAY) && defined(IP_TOS) && (defined(SOL_IP) || \
+	defined(IPPROTO_IP))
     tos = IPTOS_LOWDELAY;
+#ifdef SOL_IP
     if (setsockopt(fd, SOL_IP, IP_TOS, &tos, sizeof(tos)) < 0)
+#else
+    if (setsockopt(fd, IPPROTO_IP, IP_TOS, &tos, sizeof(tos)) < 0)
+#endif
         ret = -1;
+#endif
 
     return ret;
 
