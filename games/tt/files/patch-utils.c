--- utils.c.orig	Fri Sep 12 18:01:20 2003
+++ utils.c	Fri Sep 12 22:21:05 2003
@@ -82,7 +82,7 @@
   static char result[LINELEN];
   
   va_start (ap, fmt);
-  (void) vsprintf (result, fmt, ap);
+  (void) vsnprintf (result, LINELEN, fmt, ap);
   va_end (ap);
   return (result);
 }
