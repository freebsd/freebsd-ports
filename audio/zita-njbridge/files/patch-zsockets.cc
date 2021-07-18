--- zsockets.cc.orig	2020-03-17 09:49:07 UTC
+++ zsockets.cc
@@ -27,7 +27,7 @@
 #include <sys/ioctl.h>
 #include <sys/un.h>
 #include <netinet/tcp.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <netinet/in.h>
 #endif
 #include <net/if.h>
@@ -408,7 +408,7 @@ int sock_open_mcrecv (Sockaddr *addr, const char *ifac
 	}
         memcpy (&mcreq.ipv6mr_multiaddr, &(A6->sin6_addr), sizeof(struct in6_addr));
         mcreq.ipv6mr_interface = if_nametoindex (iface);
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
         if (setsockopt (fd, IPPROTO_IPV6, IPV6_JOIN_GROUP, (char*) &mcreq, sizeof (mcreq)))
 #else
         if (setsockopt (fd, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, (char*) &mcreq, sizeof (mcreq)))
