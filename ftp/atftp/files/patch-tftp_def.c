--- tftp_def.c.orig	2010-10-11 11:20:48.000000000 +0800
+++ tftp_def.c	2010-10-11 11:20:40.000000000 +0800
@@ -140,11 +140,14 @@
  */
 inline char *Strncpy(char *to, const char *from, size_t size)
 {
-     to[size-1] = '\000';
-     return strncpy(to, from, size - 1);
+     if (size > 0)
+     {
+	  to[size-1] = '\000';
+	  return strncpy(to, from, size - 1);
+     } else
+          return to;
 }
 
-
 /* 
  * gethostbyname replacement that is reentrant. This function is copyied
  * from the libc manual.
