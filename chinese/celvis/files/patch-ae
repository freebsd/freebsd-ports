--- recycle.c.orig	Tue Nov  6 11:53:56 1990
+++ recycle.c	Thu Aug 15 04:51:43 1996
@@ -18,7 +18,9 @@
 #ifndef NO_RECYCLE
 /* this whole file would have be skipped if NO_RECYCLE is defined */
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern long	lseek();
+#endif
 
 #define BTST(bitno, byte)	((byte) & (1 << (bitno)))
 #define BSET(bitno, byte)	((byte) |= (1 << (bitno)))
