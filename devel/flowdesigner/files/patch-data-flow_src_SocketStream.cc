--- data-flow/src/SocketStream.cc.orig	Wed Sep 21 20:21:25 2005
+++ data-flow/src/SocketStream.cc	Sat Jul  8 13:36:23 2006
@@ -194,12 +194,12 @@
 
   size_t packet_len = 0;
   unsigned int flags = 0;
-  size_t addr_len = sizeof(m_read_addr);
+  socklen_t addr_len = sizeof(m_read_addr);
 
   switch (m_type) {
   case BROADCAST_TYPE:
     #ifndef __CYGWIN__
-    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, &addr_len);
+    packet_len = recvfrom(m_read_socket, (char*)packet, size, 0, (sockaddr*) &m_read_addr, (socklen_t *)&addr_len);
     #else
     #warning CYGWIN not yet supported for broadcast network_socket
     #endif
