--- mDNSPosix/nss_mdns.c.orig	2012-04-15 06:07:19 UTC
+++ mDNSPosix/nss_mdns.c
@@ -373,13 +373,24 @@ config_is_mdns_suffix (const char * name);
         0 configuration ready
         non-zero configuration error code
  */
-errcode_t
+static errcode_t
 init_config ();
 
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
@@ -1684,7 +1695,7 @@ is_applicable_addr (
 //----------
 // Types and Constants
 
-const char * k_conf_file = "/etc/nss_mdns.conf";
+const char * k_conf_file = PREFIX"/etc/nss_mdns.conf";
 #define CONF_LINE_SIZE 1024
 
 const char k_comment_char = '#';
@@ -1789,7 +1800,7 @@ pthread_mutex_t g_config_mutex =
         0 success
         non-zero error code on failure
  */
-errcode_t
+static errcode_t
 init_config ()
 {
     if (g_config)
