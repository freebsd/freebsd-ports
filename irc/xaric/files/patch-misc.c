--- misc.c.orig	Sun Jan  8 07:56:40 2006
+++ misc.c	Sun Jan  8 07:57:39 2006
@@ -114,7 +114,7 @@
     ltime = (ltime - minutes) / 60;
     hours = ltime % 24;
     days = (ltime - hours) / 24;
-    sprintf(buffer, "%2ldd %2ldh %2ldm %2lds", days, hours, minutes, seconds);
+    sprintf(buffer, "%2dd %2dh %2dm %2ds", days, hours, minutes, seconds);
     return (*buffer ? buffer : empty_str);
 }
 
