--- examples/ipa-stream-server.c.orig	2014-09-08 08:52:08.000000000 +0300
+++ examples/ipa-stream-server.c	2015-02-16 17:05:21.000000000 +0200
@@ -4,6 +4,8 @@
 #include <string.h>
 #include <unistd.h>
 #include <arpa/inet.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 
 #include <osmocom/core/select.h>
