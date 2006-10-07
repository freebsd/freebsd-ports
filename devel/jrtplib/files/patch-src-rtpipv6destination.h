--- src/rtpipv6destination.h.orig	Tue Sep 26 22:12:59 2006
+++ src/rtpipv6destination.h	Tue Sep 26 22:13:16 2006
@@ -65,9 +65,9 @@
 		rtpaddr.sin6_family = AF_INET6;
 		rtpaddr.sin6_port = htons(portbase);
 		rtpaddr.sin6_addr = ip;
-		rtpaddr.sin6_family = AF_INET6;
-		rtpaddr.sin6_port = htons(portbase+1);
-		rtpaddr.sin6_addr = ip;
+		rtcpaddr.sin6_family = AF_INET6;
+		rtcpaddr.sin6_port = htons(portbase+1);
+		rtcpaddr.sin6_addr = ip;
 	}
 	in6_addr GetIP() const								{ return rtpaddr.sin6_addr; }
 	bool operator==(const RTPIPv6Destination &src) const				
