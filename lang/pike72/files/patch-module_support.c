--- module_support.c.orig	Sat Mar 13 23:31:07 2004
+++ module_support.c	Sat Mar 13 23:31:34 2004
@@ -314,7 +314,7 @@
   va_start(ptr, fmt);
   ret=va_get_args(s, num_args, fmt, ptr);
 #ifndef __TenDRA__
-  va_end(fmt);
+  va_end(ptr);
 #endif /* !__TenDRA */
   return ret;
 }
