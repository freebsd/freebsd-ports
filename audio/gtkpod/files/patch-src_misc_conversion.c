--- src/misc_conversion.c.orig	Thu Oct 13 18:45:35 2005
+++ src/misc_conversion.c	Thu Oct 13 18:46:50 2005
@@ -265,6 +265,7 @@
 
     if (t)
     {
+	size_t size;
 	localtime_r (&t, &tm);
 	size = strftime (buf, PATH_MAX, format, &tm);
 	buf[size] = 0;
