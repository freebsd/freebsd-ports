--- tk/unix/tkUnixPort.h.orig	2003-02-05 10:56:26.000000000 +0000
+++ tk/unix/tkUnixPort.h
@@ -125,12 +125,6 @@
 #endif
 #define MASK_SIZE howmany(FD_SETSIZE, NFDBITS)
 
-/*
- * Not all systems declare the errno variable in errno.h. so this
- * file does it explicitly.
- */
-
-extern int errno;
 
 /*
  * Define "NBBY" (number of bits per byte) if it's not already defined.
