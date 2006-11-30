--- memcached.c.orig	Sat Sep  9 21:10:21 2006
+++ memcached.c	Sat Sep 23 21:33:25 2006
@@ -1706,7 +1706,9 @@
     } else {
         setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, &flags, sizeof(flags));
         setsockopt(sfd, SOL_SOCKET, SO_LINGER, &ling, sizeof(ling));
+#if !defined(TCP_NOPUSH)
         setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, &flags, sizeof(flags));
+#endif
     }
 
     /*
