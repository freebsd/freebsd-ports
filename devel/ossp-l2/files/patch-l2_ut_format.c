--- l2_ut_format.c.orig	Tue Apr 13 19:04:15 2004
+++ l2_ut_format.c	Tue Apr 13 19:05:59 2004
@@ -1131,8 +1131,11 @@
     va_list apbak;
     char *s;
     int rv;
-
+#ifdef __amd64__
+    va_copy(apbak,ap);
+#else
     apbak = ap;
+#endif
     if ((rv = l2_util_vsprintf(NULL, -1, fmt, ap)) == -1)
         return NULL;
     if ((s = malloc(rv+1)) == NULL)
