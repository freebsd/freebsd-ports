--- include/netmain.h.orig	Wed Feb 12 22:08:55 2003
+++ include/netmain.h	Thu Jan 22 17:33:55 2004
@@ -34,7 +34,8 @@
 
 struct qsockaddr
 {
-	short qsa_family;
+	unsigned char dummy;
+	unsigned char qsa_family;
 	unsigned char qsa_data[14];
 };
