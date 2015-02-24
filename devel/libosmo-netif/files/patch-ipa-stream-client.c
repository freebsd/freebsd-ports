--- examples/ipa-stream-client.c.orig	2014-09-08 08:52:08.000000000 +0300
+++ examples/ipa-stream-client.c	2015-02-16 17:06:50.000000000 +0200
@@ -6,6 +6,8 @@
 #include <signal.h>
 #include <sys/time.h>
 #include <arpa/inet.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 
 #include <osmocom/core/select.h>
