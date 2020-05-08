--- src/common/net/sock.c.orig	2019-05-15 08:58:13 UTC
+++ src/common/net/sock.c
@@ -742,7 +742,7 @@ sock_t sock_get_server_socket (int port, const char *s
 
         setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&on, sizeof(on));
         on = 0;
-#ifdef IPV6_V6ONLY
+#if defined(__BSD_VISIBLE) && defined(IPV6_V6ONLY)
         setsockopt (sock, IPPROTO_IPV6, IPV6_V6ONLY, &on, sizeof on);
 #endif
 
