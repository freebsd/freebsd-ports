--- lib/direct/stream.c.orig	2012-05-23 13:43:12 UTC
+++ lib/direct/stream.c
@@ -429,7 +429,7 @@ net_connect( struct addrinfo *addr, int 
                          req.imr_multiaddr.s_addr = saddr->sin_addr.s_addr;
                          req.imr_interface.s_addr = 0;
 
-                         err = setsockopt( fd, SOL_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req) );
+                         err = setsockopt( fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req) );
                          if (err < 0) {
                               ret = errno2result( errno );
                               D_PERROR( "Direct/Stream: Could not join multicast group (%u.%u.%u.%u)!\n",
