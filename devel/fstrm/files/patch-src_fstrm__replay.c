--- src/fstrm_replay.c.orig	2018-05-10 14:44:28 UTC
+++ src/fstrm_replay.c
@@ -15,6 +15,8 @@
  */
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <sys/uio.h>
 #include <string.h>
 #include <stdio.h>
