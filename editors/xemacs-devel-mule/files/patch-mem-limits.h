--- src/mem-limits.h.orig	Sat Sep 11 08:28:41 2004
+++ src/mem-limits.h	Sat Aug 19 08:23:52 2006
@@ -80,7 +80,11 @@
 static POINTER data_space_start;
 
 /* Number of bytes of writable memory we can expect to be able to get */
+#ifdef _RLIM_T_DECLARED
+extern rlim_t lim_data;
+#else
 extern unsigned long lim_data;
+#endif
 
 /* The implementation of get_lim_data() is very machine dependent. */
 
