--- src/ecgitk.c.orig	2014-11-24 13:35:51.000000000 -0800
+++ src/ecgitk.c	2014-11-24 13:36:16.000000000 -0800
@@ -23,7 +23,7 @@
 {
 	char buf[4096];
 	int used;
-	va_list *ap;
+	va_list ap;
 
 	va_start(ap, (void*)format);
 	used=vsnprintf(buf, 4095, format, ap);
