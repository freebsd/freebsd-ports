--- src/libretro/platform.cpp.orig	2022-09-11 22:46:37 UTC
+++ src/libretro/platform.cpp
@@ -13,6 +13,7 @@
 #include <unistd.h>
 #include <arpa/inet.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #define socket_t    int
 #define sockaddr_t  struct sockaddr
 #define closesocket close
