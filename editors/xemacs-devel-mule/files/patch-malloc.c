--- src/malloc.c.orig	Tue Oct 25 14:16:26 2005
+++ src/malloc.c	Sat Aug 19 08:25:42 2006
@@ -285,7 +285,11 @@
 static char busy[30];
 
 /* Number of bytes of writable memory we can expect to be able to get */
+#ifdef _RLIM_T_DECLARED
+extern rlim_t lim_data;
+#else
 extern unsigned long lim_data;
+#endif
 
 /* Level number of warnings already issued.
   0 -- no warnings issued.
