--- src/app-utils/guile-util.c.orig	2014-01-19 00:44:17.000000000 +0100
+++ src/app-utils/guile-util.c	2014-01-27 22:15:08.578610605 +0100
@@ -1083,6 +1083,8 @@
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
