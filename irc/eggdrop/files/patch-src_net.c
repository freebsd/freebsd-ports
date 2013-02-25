$NetBSD: patch-src_net.c,v 1.1 2012/11/16 00:35:28 joerg Exp $

--- src/net.c.orig	2012-11-15 10:30:07.000000000 +0000
+++ src/net.c
@@ -564,7 +564,7 @@ int open_address_listen(IP addr, int *po
 /* Returns a socket number for a listening socket that will accept any
  * connection -- port # is returned in port
  */
-inline int open_listen(int *port)
+int open_listen(int *port)
 {
   return open_address_listen(myip[0] ? getmyip() : INADDR_ANY, port);
 }
