
$FreeBSD$

--- ez-ipupdate.c.orig
+++ ez-ipupdate.c
@@ -798,7 +798,7 @@
     sprintf(buf, "message incomplete because your OS sucks: %s\n", fmt);
 #endif
 
-    syslog(LOG_NOTICE, buf);
+    syslog(LOG_NOTICE, "%s", buf);
   }
   else
   {
