--- src/app-utils/guile-util.c.orig	2008-01-08 10:06:47.000000000 +0900
+++ src/app-utils/guile-util.c	2009-09-01 03:04:30.000000000 +0900
@@ -1304,6 +1304,8 @@
 
   g_return_val_if_fail(s && format, -1);
 
+  bzero(&tm, sizeof(tm));
+
   if (!strptime(s, format, &tm))
     return -1;
 
