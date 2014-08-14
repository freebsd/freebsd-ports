--- ./mDNSPosix/nss_mdns.c.orig	2012-04-15 08:07:19.000000000 +0200
+++ ./mDNSPosix/nss_mdns.c	2013-11-05 11:00:14.000000000 +0100
@@ -379,7 +379,18 @@
 #define ENTNAME  hostent
 #define DATABASE "hosts"
 
-#include <nss.h>
+#if defined __FreeBSD__
+# include <nsswitch.h>
+enum nss_status {
+  NSS_STATUS_SUCCESS = NS_SUCCESS,
+  NSS_STATUS_NOTFOUND = NS_NOTFOUND,
+  NSS_STATUS_UNAVAIL = NS_UNAVAIL,
+  NSS_STATUS_TRYAGAIN = NS_TRYAGAIN,
+  NSS_STATUS_RETURN = NS_RETURN
+};
+#elif defined __Linux__
+# include <nss.h>
+#endif
 // For nss_status
 #include <netdb.h>
 // For hostent
@@ -1684,7 +1695,7 @@
 //----------
 // Types and Constants
 
-const char * k_conf_file = "/etc/nss_mdns.conf";
+const char * k_conf_file = PREFIX"/etc/nss_mdns.conf";
 #define CONF_LINE_SIZE 1024
 
 const char k_comment_char = '#';
