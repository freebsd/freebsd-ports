--- src/gallium/auxiliary/util/u_network.c.orig	2018-01-23 18:08:49 UTC
+++ src/gallium/auxiliary/util/u_network.c
@@ -9,7 +9,7 @@
 #  include <winsock2.h>
 #  include <windows.h>
 #  include <ws2tcpip.h>
-#elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_HAIKU) || \
+#elif defined(PIPE_OS_LINUX) || defined(PIPE_OS_BSD) || defined(PIPE_OS_HAIKU) || \
    defined(PIPE_OS_APPLE) || defined(PIPE_OS_CYGWIN) || defined(PIPE_OS_SOLARIS)
 #  include <sys/socket.h>
 #  include <netinet/in.h>
