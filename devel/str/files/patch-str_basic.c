--- str_basic.c.orig	Tue Apr 13 19:28:46 2004
+++ str_basic.c	Tue Apr 13 19:29:51 2004
@@ -133,7 +133,11 @@
         return NULL;
 
     /* determine required target string length */
+#ifdef __amd64__
+    va_copy(ap_safe, ap);
+#else
     ap_safe = ap;
+#endif
     n = str_len(s);
     while ((cp = va_arg(ap, char *)) != NULL)
         n += str_len(cp);
