--- src/css.c.orig	2020-09-30 16:32:21 UTC
+++ src/css.c
@@ -51,6 +51,10 @@
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
 
+#ifndef SOL_TCP
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 // makes sides of int[] from pipe2() clearer
 #define PIPE_RD 0
 #define PIPE_WR 1
