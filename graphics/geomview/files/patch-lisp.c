--- src/lib/oogl/lisp/lisp.c.orig	Fri Sep  1 15:38:16 2000
+++ src/lib/oogl/lisp/lisp.c	Mon Aug 12 17:02:09 2002
@@ -2110,7 +2110,7 @@
     va_list *a_list;
     unsigned long *x;
 {
-  *x = va_arg(*a_list, ulong);
+  *x = va_arg(*a_list, unsigned long);
 }
 
 LObject *ulongparse(Lake *lake)
