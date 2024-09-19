--- src/UdpDataProtocol.cpp.orig	2024-09-14 06:44:01 UTC
+++ src/UdpDataProtocol.cpp
@@ -383,12 +383,14 @@ bool UdpDataProtocol::setSocketQos(socket_type& sock_f
     }
 
     // Set 802.1q QoS priority
+#  if !defined(__FreeBSD__) // is there a FreeBSD replacement?
     int priority = 6;
     result = ::setsockopt(sock_fd, SOL_SOCKET, SO_PRIORITY, &priority, sizeof(priority));
     if (result != 0) {
         std::cerr << "setsockopt failed. Error: " << errno << std::endl;
         return false;
     }
+#  endif
 #endif
 
     return true;
