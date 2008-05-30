--- lib/direct/stream.c.orig	2007-12-15 14:30:28.000000000 +0200
+++ lib/direct/stream.c	2008-03-16 14:51:44.000000000 +0200
@@ -429,7 +429,7 @@
                          req.imr_multiaddr.s_addr = saddr->sin_addr.s_addr;
                          req.imr_interface.s_addr = 0;
 
-                         err = setsockopt( fd, SOL_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req) );
+                         err = setsockopt( fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &req, sizeof(req) );
                          if (err < 0) {
                               ret = errno2result( errno );
                               D_PERROR( "Direct/Stream: Could not join multicast group (%u.%u.%u.%u)!\n",
