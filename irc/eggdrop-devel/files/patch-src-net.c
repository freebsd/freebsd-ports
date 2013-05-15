--- src/net.c.orig	2013-05-13 15:18:26.000000000 +0200
+++ src/net.c	2013-05-13 15:18:34.000000000 +0200
@@ -560,7 +560,7 @@
 /* Returns a socket number for a listening socket that will accept any
  * connection -- port # is returned in port
  */
-inline int open_listen(int *port)
+int open_listen(int *port)
 {
   int sock;
   sockname_t name;
