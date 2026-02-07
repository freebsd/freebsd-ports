--- tuntap.c.orig	2018-10-15 10:45:27 UTC
+++ tuntap.c
@@ -33,6 +33,8 @@
 #include "tuntap.h"
 #include "private.h"
 
+t_tuntap_log tuntap_log;
+
 struct device *
 tuntap_init(void) {
 	struct device *dev = NULL;
