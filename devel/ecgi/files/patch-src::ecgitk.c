--- src/ecgitk.c.orig	Tue Feb 13 21:09:37 2001
+++ src/ecgitk.c	Sat Sep 14 01:22:11 2002
@@ -23,7 +23,7 @@
 {
 	char buf[4096];
 	int used;
-	va_list *ap;
+	va_list ap;
 	
 	va_start(ap, (void*)format);
 	used=vsnprintf(buf, 4095, format, ap);
