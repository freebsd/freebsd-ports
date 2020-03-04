--- src/network.c.orig	2020-03-02 18:11:22 UTC
+++ src/network.c
@@ -728,7 +728,7 @@ static int make_sock(union mysockaddr *addr, int type,
     {
 #ifdef TCP_FASTOPEN
       int qlen = 5;                           
-      setsockopt(fd, SOL_TCP, TCP_FASTOPEN, &qlen, sizeof(qlen));
+      setsockopt(fd, IPPROTO_TCP, TCP_FASTOPEN, &qlen, sizeof(qlen));
 #endif
       
       if (listen(fd, TCP_BACKLOG) == -1)
