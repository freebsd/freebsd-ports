--- a/block/sheepdog.c
+++ b/block/sheepdog.c
@@ -14,7 +14,12 @@
 #include <ws2tcpip.h>
 #else
 #include <netdb.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#else
 #include <netinet/tcp.h>
+#endif
 
 #define closesocket(s) close(s)
 #endif
