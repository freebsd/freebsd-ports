--- update.c.orig	Tue Oct 31 01:10:02 2000
+++ update.c	Thu Jul 25 06:47:36 2002
@@ -26,6 +26,8 @@
 extern int backmx_flag;
 /* Flag set by '--static' (Added by Patrick D.) */
 extern int static_flag;
+extern int dynamic_flag;
+extern int custom_flag;
 /* Vars for other options */
 extern char *ip_address;
 extern char *host_id;
@@ -125,11 +127,14 @@
   strcat(buf_out, "/nic/update?system=");
 
   if (static_flag)
-    strcat(buf_out, "stat");
-  else
-    strcat(buf_out, "dyn");
+    strcat(buf_out, "statdns");
+  else if (custom_flag)
+    strcat(buf_out, "custom");
+  else 
+    strcat(buf_out, "dyndns");
 
-  strcat(buf_out, "dns&hostname=");
+
+  strcat(buf_out, "&hostname=");
   strcat(buf_out, host_id);
 
   if (ip_address)
