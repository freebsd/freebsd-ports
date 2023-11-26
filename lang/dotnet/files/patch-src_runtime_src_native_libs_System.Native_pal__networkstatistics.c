--- src/runtime/src/native/libs/System.Native/pal_networkstatistics.c.orig	2023-11-01 21:55:24 UTC
+++ src/runtime/src/native/libs/System.Native/pal_networkstatistics.c
@@ -58,6 +58,8 @@
 #elif HAVE_IOS_NETINET_IP_VAR_H
 #include "ios/netinet/ip_var.h"
 #endif
+#include <sys/callout.h>
+#include <sys/osd.h>
 #include <netinet/tcp_var.h>
 #include <netinet/tcp.h>
 #if HAVE_TCP_FSM_H
