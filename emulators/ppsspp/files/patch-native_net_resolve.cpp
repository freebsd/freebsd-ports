--- native/net/resolve.cpp.orig	2015-02-23 23:22:58 UTC
+++ native/net/resolve.cpp
@@ -14,11 +14,8 @@
 #undef min
 #undef max
 #else
-#if defined(__FreeBSD__)
 #include <netinet/in.h>
-#else
 #include <arpa/inet.h>
-#endif
 #include <netdb.h>
 #include <sys/socket.h>
 #include <unistd.h>
