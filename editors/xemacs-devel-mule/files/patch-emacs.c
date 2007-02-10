--- src/emacs.c.orig	Sat Aug 19 08:26:45 2006
+++ src/emacs.c	Sat Aug 19 08:27:35 2006
@@ -592,7 +592,11 @@
 
 /* Number of bytes of writable memory we can expect to be able to get:
    Leave this as an unsigned int because it could potentially be 4G */
+#ifdef _RLIM_T_DECLARED
+rlim_t lim_data;
+#else
 unsigned long lim_data;
+#endif
 
 /* WARNING!
 
