--- blk.c.orig	1990-11-06 19:53:55 UTC
+++ blk.c
@@ -19,7 +19,9 @@
 # define NBUFS	5		/* must be at least 3 -- more is better */
 #endif
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern long lseek();
+#endif
 
 /*------------------------------------------------------------------------*/
 
