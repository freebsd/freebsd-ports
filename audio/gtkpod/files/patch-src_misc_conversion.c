--- src/misc_conversion.c.orig	Wed Mar 16 19:17:01 2005
+++ src/misc_conversion.c	Wed Mar 16 19:17:50 2005
@@ -143,8 +143,9 @@
 
     if (t)
     {
+        size_t size;
 	localtime_r (&t, &tm);
-	size_t size = strftime (buf, PATH_MAX, format, &tm);
+	size = strftime (buf, PATH_MAX, format, &tm);
 	buf[size] = 0;
 	return g_locale_to_utf8 (buf, -1, NULL, NULL, NULL);
     }
