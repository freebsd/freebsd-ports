--- util/str_util.c.orig	Wed Jul 16 23:56:06 2003
+++ util/str_util.c	Sat Feb  7 22:19:51 2004
@@ -1103,7 +1103,11 @@
 /*
  * Determine required size for destination buffer.
  */
+  #if defined(__amd64__)
+  va_copy(orig_ap, ap);
+  #else
   orig_ap = ap;
+  #endif
   len = strlen(str);
 
   while ( (sp = va_arg(ap, char *))!=NULL ) len += strlen(sp);
