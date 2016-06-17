--- src/multiskkserv-ctl.c.orig	2002-01-12 21:10:13 UTC
+++ src/multiskkserv-ctl.c
@@ -168,7 +168,7 @@ show_stat(char *remote, int port, int fa
   char rbuf[SKKSERV_REQUEST_SIZE];
 
   if ((sock = socket_connect(remote, &sstr, port, (char *)SKKSERV_SERVICE, family)) < 0) {
-    fprintf(stderr, __FUNCTION__ ": cannot make a connection.\n");
+    fprintf(stderr, "%s%s", __FUNCTION__, ": cannot make a connection.\n");
     return;
   }
 
