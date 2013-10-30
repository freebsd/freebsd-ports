--- tftp_def.c.orig	2004-02-13 11:16:09.000000000 +0800
+++ tftp_def.c	2013-10-30 13:34:05.000000000 +0800
@@ -88,7 +88,7 @@
                res->tv_usec -= 1000000;
                return -1;
           }
-          else if (res->tv_usec <= 0);
+          else
           {
                return -1;
           }
@@ -138,13 +138,16 @@
 /*
  * This is a strncpy function that take care of string NULL termination
  */
-inline char *Strncpy(char *to, const char *from, size_t size)
+char *Strncpy(char *to, const char *from, size_t size)
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
