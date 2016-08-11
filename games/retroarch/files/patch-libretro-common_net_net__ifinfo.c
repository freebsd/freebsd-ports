--- libretro-common/net/net_ifinfo.c.orig	2016-07-04 20:02:01 UTC
+++ libretro-common/net/net_ifinfo.c
@@ -44,6 +44,8 @@
 
 #include <net/net_ifinfo.h>
 
+#include <netinet/in.h>
+
 void net_ifinfo_free(net_ifinfo_t *list)
 {
    unsigned k;
