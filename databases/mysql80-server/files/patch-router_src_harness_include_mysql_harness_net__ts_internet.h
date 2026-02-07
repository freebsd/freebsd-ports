--- router/src/harness/include/mysql/harness/net_ts/internet.h.orig	2024-07-12 19:15:25 UTC
+++ router/src/harness/include/mysql/harness/net_ts/internet.h
@@ -44,6 +44,7 @@
 #include <arpa/inet.h>    // inet_ntop
 #include <netdb.h>        // getaddrinfo
 #include <netinet/in.h>   // in_addr_t
+#include <sys/types.h>    // u_int32_t
 #include <netinet/ip6.h>  // in6_addr_t
 #include <netinet/tcp.h>  // TCP_NODELAY
 #include <sys/ioctl.h>    // ioctl
