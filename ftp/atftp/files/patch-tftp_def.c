--- tftp_def.c.orig	2010-10-05 09:43:06.000000000 +0800
+++ tftp_def.c	2010-10-05 09:43:53.000000000 +0800
@@ -140,8 +140,10 @@
  */
 inline char *Strncpy(char *to, const char *from, size_t size)
 {
-     to[size-1] = '\000';
-     return strncpy(to, from, size - 1);
+     strncpy(to, from, size);
+     if (size > 0)
+	  to[size-1] = '\000';
+     return to;
 }
 
 
