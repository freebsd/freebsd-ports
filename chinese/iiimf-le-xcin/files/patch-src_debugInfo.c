--- src/debugInfo.c.orig	Mon Aug 16 08:18:25 2004
+++ src/debugInfo.c	Thu Oct 14 00:46:26 2004
@@ -12,9 +12,9 @@
 
 void debug(const char *format, ...)
 {
+    va_list args;
     if(!isDebugMode()) return;
 
-    va_list args;
     va_start(args, format);
     vfprintf(stderr, format, args);
     fprintf(stderr, "\n");
