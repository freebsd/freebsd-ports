--- data-flow/src/SocketStream.cc.orig	Thu Aug 26 18:31:31 2004
+++ data-flow/src/SocketStream.cc	Thu Mar 10 17:36:08 2005
@@ -190,7 +190,7 @@
 
   size_t packet_len = 0;
   unsigned int flags = 0;
-  size_t addr_len = sizeof(m_read_addr);
+  socklen_t addr_len = sizeof(m_read_addr);
 
   switch (m_type) {
   case BROADCAST_TYPE:
