--- conserver/consent.c.orig	Wed Oct 17 04:03:05 2001
+++ conserver/consent.c	Wed Feb 27 09:49:59 2002
@@ -66,6 +66,12 @@
 
 BAUD baud[] = {
     {"Netwk", 0},
+#ifdef B115200
+    {"115200", 115200},
+#endif
+#ifdef B57600
+    {"57600", B57600},
+#endif
 #if defined(B38400)
     {"38400", B38400},
 #endif
