--- memcached.c.orig	Mon Jul  3 13:04:31 2006
+++ memcached.c	Mon Jul  3 13:04:40 2006
@@ -1146,9 +1146,7 @@
     setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &flags, sizeof(flags));
     setsockopt(sfd, SOL_SOCKET, SO_KEEPALIVE, &flags, sizeof(flags));
     setsockopt(sfd, SOL_SOCKET, SO_LINGER, &ling, sizeof(ling));
-#if !defined(TCP_NOPUSH)
     setsockopt(sfd, IPPROTO_TCP, TCP_NODELAY, &flags, sizeof(flags));
-#endif
 
     /* 
      * the memset call clears nonstandard fields in some impementations
