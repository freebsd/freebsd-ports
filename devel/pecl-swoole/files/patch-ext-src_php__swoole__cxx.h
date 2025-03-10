--- ext-src/php_swoole_cxx.h.orig	2024-12-16 08:02:21 UTC
+++ ext-src/php_swoole_cxx.h
@@ -200,6 +200,10 @@ using tcp_info = tcp_connection_info;
 using tcp_info = tcp_connection_info;
 #endif
 
+#ifdef __FreeBSD__
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 #ifdef TCP_INFO
 std::unordered_map<std::string, uint64_t> sw_socket_parse_tcp_info(tcp_info *info);
 #endif
