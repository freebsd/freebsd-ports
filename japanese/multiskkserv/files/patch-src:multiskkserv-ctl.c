--- src/multiskkserv-ctl.c.orig	Sun Jan 13 06:10:13 2002
+++ src/multiskkserv-ctl.c	Fri Aug 13 19:50:45 2004
@@ -168,7 +168,7 @@
   char rbuf[SKKSERV_REQUEST_SIZE];
 
   if ((sock = socket_connect(remote, &sstr, port, (char *)SKKSERV_SERVICE, family)) < 0) {
-    fprintf(stderr, __FUNCTION__ ": cannot make a connection.\n");
+    fprintf(stderr, "%s%s", __FUNCTION__, ": cannot make a connection.\n");
     return;
   }
 
