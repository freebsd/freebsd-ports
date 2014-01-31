--- EMULib/Unix/NetUnix.c.orig	2014-01-30 23:33:17.000000000 +0700
+++ EMULib/Unix/NetUnix.c	2014-01-30 23:34:48.000000000 +0700
@@ -19,6 +19,8 @@
 #include <stdio.h>
 #include <netdb.h>
 #include <errno.h>
+#include <netinet/in.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -30,6 +32,10 @@
 #define printf LOGI
 #endif
 
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 static volatile int IsServer  = 0;
 static volatile int Socket    = -1;
 static volatile int Blocking  = 1;
