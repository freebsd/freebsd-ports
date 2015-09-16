--- native/net/http_client.h.orig	2015-02-23 23:22:58 UTC
+++ native/net/http_client.h
@@ -11,11 +11,8 @@
 #define NOMINMAX
 #include <winsock2.h>
 #else
-#if defined(__FreeBSD__) || defined(__SYMBIAN32__)
 #include <netinet/in.h>
-#else
 #include <arpa/inet.h>
-#endif
 #include <sys/socket.h>
 #include <netdb.h>
 #endif
