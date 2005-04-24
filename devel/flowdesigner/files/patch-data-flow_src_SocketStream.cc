--- data-flow/src/SocketStream.cc.orig	Sun Apr 24 15:16:43 2005
+++ data-flow/src/SocketStream.cc	Sun Apr 24 15:16:32 2005
@@ -190,12 +190,12 @@
 
   size_t packet_len = 0;
   unsigned int flags = 0;
-  size_t addr_len = sizeof(m_read_addr);
+  socklen_t addr_len = sizeof(m_read_addr);
 
   switch (m_type) {
   case BROADCAST_TYPE:
 
-    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, &addr_len);
+    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, (socklen_t *)&addr_len);
 
     if ((int) packet_len < 0) {
       if (errno == EAGAIN) {
