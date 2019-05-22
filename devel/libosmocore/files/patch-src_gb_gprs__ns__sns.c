--- src/gb/gprs_ns_sns.c.orig	2019-05-22 09:31:16 UTC
+++ src/gb/gprs_ns_sns.c
@@ -11,6 +11,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 
+#include <sys/socket.h>
+
 #include <osmocom/core/fsm.h>
 #include <osmocom/core/msgb.h>
 #include <osmocom/core/signal.h>
