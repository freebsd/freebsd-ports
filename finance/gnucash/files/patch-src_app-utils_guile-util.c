--- src/app-utils/guile-util.c.orig	2017-09-19 23:23:17 UTC
+++ src/app-utils/guile-util.c
@@ -1083,6 +1083,8 @@ gnc_parse_time_to_time64 (const gchar *s, const gchar 
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
