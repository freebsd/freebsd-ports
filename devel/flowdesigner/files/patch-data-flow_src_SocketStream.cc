--- data-flow/src/SocketStream.cc.orig	Tue Mar  8 18:52:37 2005
+++ data-flow/src/SocketStream.cc	Tue Mar  8 18:21:43 2005
@@ -195,7 +195,7 @@ size_t network_socket::recv_packet(unsig
   switch (m_type) {
   case BROADCAST_TYPE:
 
-    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, &addr_len);
+    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, (socklen_t *)&addr_len);
 
     if ((int) packet_len < 0) {
       if (errno == EAGAIN) {
