--- cfg_fmt.c.orig	Tue Apr 13 18:52:54 2004
+++ cfg_fmt.c	Tue Apr 13 18:53:51 2004
@@ -1131,8 +1131,11 @@
     va_list apbak;
     char *s;
     int rv;
-
+#ifdef __amd64__
+    va_copy(apbak, ap);
+#else
     apbak = ap;
+#endif
     if ((rv = cfg_fmt_vsprintf(NULL, -1, fmt, ap)) == -1)
         return NULL;
     if ((s = malloc(rv+1)) == NULL)
