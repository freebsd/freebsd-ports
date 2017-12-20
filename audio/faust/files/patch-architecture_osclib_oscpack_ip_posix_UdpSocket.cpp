--- architecture/osclib/oscpack/ip/posix/UdpSocket.cpp.orig	2017-06-07 15:07:18 UTC
+++ architecture/osclib/oscpack/ip/posix/UdpSocket.cpp
@@ -232,8 +232,10 @@ public:
 		mh.msg_iovlen = 1;
 
 		// Set socket option
+#if defined(IP_PKTINFO)
 		int val = 1;
 		setsockopt (socket_, IPPROTO_IP, IP_PKTINFO, &val, sizeof(val));
+#endif
 		int result = recvmsg(socket_, &mh, 0);
 		if( result < 0 )
 			return 0;
@@ -245,14 +247,20 @@ public:
 		{
 			// ignore the control headers that don't match what we want
 			if (cmsg->cmsg_level != IPPROTO_IP ||
+#if defined(IP_PKTINFO)
 				cmsg->cmsg_type != IP_PKTINFO)
+#else
+				false)
+#endif
 			{
 				continue;
 			}
+#if defined(IP_PKTINFO)
 			// Get the destination address
 			struct in_pktinfo *pi = (struct in_pktinfo *)CMSG_DATA(cmsg);
 			// pi->ipi_addr is the destination in_addr
 			remoteEndpoint.destAddress = ntohl(pi->ipi_addr.s_addr);
+#endif
 		}
 		remoteEndpoint.address = ntohl(peeraddr.sin_addr.s_addr);
 		remoteEndpoint.port = ntohs(peeraddr.sin_port);
