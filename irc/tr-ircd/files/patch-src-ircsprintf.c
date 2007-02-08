--- src/ircsprintf.c.orig	Tue Feb  6 12:54:02 2007
+++ src/ircsprintf.c	Tue Feb  6 12:54:20 2007
@@ -336,7 +336,8 @@
     const char *format = pattern;
     char *buf = str;
     int len = 0;
-    va_list ap = vl;
+    va_list ap;
+    va_copy(ap,vl);
 
     while (*format) {
 	switch (*format) {
