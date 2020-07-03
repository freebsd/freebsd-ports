--- bindings/guile/gnc-engine-guile.c.orig	2020-06-27 22:33:56 UTC
+++ bindings/guile/gnc-engine-guile.c
@@ -1900,6 +1900,8 @@ gnc_parse_time_to_time64 (const gchar *s, const gchar 
 
     g_return_val_if_fail(s && format, -1);
 
+    bzero(&tm, sizeof(tm));
+
     if (!strptime(s, format, &tm))
         return -1;
 
