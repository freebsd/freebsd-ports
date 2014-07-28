--- glib.h.orig	Sun Sep  5 23:34:07 1999
+++ glib.h	Thu Sep 16 01:32:54 1999
@@ -108,7 +108,11 @@
  *  defined then the current definition is correct.
  */
 #ifndef	NULL
+#ifdef __cplusplus
+#define	NULL	(0)
+#else
 #define	NULL	((void*) 0)
+#endif
 #endif
 
 #ifndef	FALSE
