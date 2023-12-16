--- recycle.c.orig	1990-11-06 19:53:56 UTC
+++ recycle.c
@@ -18,7 +18,9 @@
 #ifndef NO_RECYCLE
 /* this whole file would have be skipped if NO_RECYCLE is defined */
 
+#if !(defined(BSD) && (BSD >= 199103))
 extern long	lseek();
+#endif
 
 #define BTST(bitno, byte)	((byte) & (1 << (bitno)))
 #define BSET(bitno, byte)	((byte) |= (1 << (bitno)))
