--- port.h.orig	Tue Sep  7 00:38:10 1999
+++ port.h	Sun Dec  7 02:46:07 2003
@@ -42,7 +42,7 @@
 /* If endian.h is not present, it can be handled in the code below, */
 /* but if you have this file, it can make it more fool proof. */
 #if (defined(XFRACT) && !defined(__sun))
-#if defined(sgi)
+#if defined(sgi) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
@@ -288,6 +288,9 @@
 #define DO_NOT_USE_LONG_DOUBLE
 #endif
 #ifdef sun
+#define DO_NOT_USE_LONG_DOUBLE
+#endif
+#ifdef __FreeBSD__
 #define DO_NOT_USE_LONG_DOUBLE
 #endif
 
