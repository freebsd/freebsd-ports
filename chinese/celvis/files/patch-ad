--- blk.c.orig	Tue Nov  6 11:53:55 1990
+++ blk.c	Thu Aug 15 04:47:18 1996
@@ -19,7 +19,9 @@
 # define NBUFS	5		/* must be at least 3 -- more is better */
 #endif
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern long lseek();
+#endif
 
 /*------------------------------------------------------------------------*/
 
