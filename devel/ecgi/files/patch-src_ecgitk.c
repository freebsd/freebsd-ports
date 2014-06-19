--- src/ecgitk.c.orig	2014-04-26 08:53:43.000000000 +0000
+++ src/ecgitk.c
@@ -23,7 +23,7 @@ int ctkRedirect(const char *format, ...)
 {
 	char buf[4096];
 	int used;
-	va_list *ap;
+	va_list ap;
 	
 	va_start(ap, (void*)format);
 	used=vsnprintf(buf, 4095, format, ap);
