--- ./eperl_sys.c.orig	1998-07-27 04:41:34.000000000 -0400
+++ ./eperl_sys.c	2009-01-29 13:27:29.000000000 -0500
@@ -239,8 +239,8 @@
     char timestr[128];
 
     tm = localtime(t);
-    sprintf(timestr, "%02d-%02d-19%02d %02d:%02d",
-                      tm->tm_mday, tm->tm_mon+1, tm->tm_year,
+    sprintf(timestr, "%02d-%02d-%04d %02d:%02d",
+                      tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900,
                       tm->tm_hour, tm->tm_min);
     return strdup(timestr);
 }
