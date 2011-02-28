--- src/app-utils/guile-util.c.orig	2010-12-29 16:06:05.000000000 +0100
+++ src/app-utils/guile-util.c	2010-12-29 16:06:38.000000000 +0100
@@ -1317,6 +1317,8 @@ gnc_parse_time_to_timet(const gchar *s, 
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
