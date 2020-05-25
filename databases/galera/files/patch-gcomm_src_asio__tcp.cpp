--- gcomm/src/asio_tcp.cpp.orig	2020-01-23 13:38:58 UTC
+++ gcomm/src/asio_tcp.cpp
@@ -775,7 +775,7 @@ void gcomm::AsioTcpSocket::assign_remote_addr()
 gcomm::SocketStats gcomm::AsioTcpSocket::stats() const
 {
     SocketStats ret;
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__)
     struct tcp_info tcpi;
     memset(&tcpi, 0, sizeof(tcpi));
     socklen_t tcpi_len(sizeof(tcpi));
@@ -798,7 +798,7 @@ gcomm::SocketStats gcomm::AsioTcpSocket::stats() const
         ret.send_queue_bytes = send_q_.queued_bytes();
         ret.send_queue_segments = send_q_.segments();
     }
-#endif /* __linux__ || __FreeBSD__ */
+#endif /* __linux__ */
     return ret;
 }
 
