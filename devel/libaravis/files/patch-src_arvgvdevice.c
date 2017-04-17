--- src/arvgvdevice.c.orig	2017-04-10 13:30:09 UTC
+++ src/arvgvdevice.c
@@ -20,6 +20,8 @@
  * @short_description: GigEVision device
  */
 
+#include <sys/param.h>
+
 #include <arvgvdeviceprivate.h>
 #include <arvdeviceprivate.h>
 #include <arvgc.h>
@@ -36,9 +38,14 @@
 #include <arvenumtypes.h>
 #include <string.h>
 #include <stdlib.h>
-#ifndef __APPLE__
+#ifdef __linux__
 #include <linux/ip.h>
 #endif
+#ifdef BSD
+#include <netinet/in.h>
+#include <netinet/ip.h>
+#define iphdr	ip
+#endif
 #include <netinet/udp.h>
 
 static GObjectClass *parent_class = NULL;
