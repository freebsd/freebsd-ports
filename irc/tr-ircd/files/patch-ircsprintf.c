--- src/ircsprintf.c.orig	Sat Aug 21 13:36:50 2004
+++ src/ircsprintf.c	Sat Aug 21 13:37:15 2004
@@ -316,7 +316,8 @@
     const char *format = pattern;
     char *buf = str;
     int len = 0;
-    va_list ap = vl;
+    va_list ap;
+    va_copy(ap,vl);
 
     while (*format) {
 	switch (*format) {
