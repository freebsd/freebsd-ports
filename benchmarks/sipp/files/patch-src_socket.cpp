--- src/socket.cpp.orig	2018-07-08 10:42:40 UTC
+++ src/socket.cpp
@@ -338,7 +338,7 @@ const char *sip_tls_error_string(SSL *ss
 
 static char* get_inet_address(const struct sockaddr_storage* addr, char* dst, int len)
 {
-    if (getnameinfo(_RCAST(struct sockaddr*, addr), sizeof(*addr),
+    if (getnameinfo(_RCAST(struct sockaddr*, addr), SOCK_ADDR_SIZE(addr),
                     dst, len, NULL, 0, NI_NUMERICHOST) != 0) {
         snprintf(dst, len, "addr not supported");
     }
