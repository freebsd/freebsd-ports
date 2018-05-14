--- libgnucash/app-utils/guile-util.c.orig	2018-03-31 22:46:38 UTC
+++ libgnucash/app-utils/guile-util.c
@@ -1095,6 +1095,8 @@ gnc_parse_time_to_time64 (const gchar *s, const gchar 
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
