- workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=264865

--- src/UdpDataProtocol.cpp.orig	2022-06-24 05:34:49 UTC
+++ src/UdpDataProtocol.cpp
@@ -293,8 +293,10 @@ int UdpDataProtocol::bindSocket()
     }
 
     // Set 802.1q QoS priority
+#  if !defined(__FreeBSD__) // is there a FreeBSD replacement?
     int priority = 6;
     ::setsockopt(sock_fd, SOL_SOCKET, SO_PRIORITY, &priority, sizeof(priority));
+#  endif
 #endif
 
     // Bind the Socket
