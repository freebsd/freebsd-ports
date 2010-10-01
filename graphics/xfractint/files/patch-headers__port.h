--- ./headers/port.h.orig	2008-02-17 17:26:16.000000000 -0500
+++ ./headers/port.h	2010-01-27 13:52:46.000000000 -0500
@@ -44,7 +44,7 @@
 /* If endian.h is not present, it can be handled in the code below, */
 /* but if you have this file, it can make it more fool proof. */
 #if (defined(XFRACT) && !defined(__sun))
-#if defined(sgi)
+#if defined(sgi) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
@@ -319,7 +319,7 @@
 /* HP-UX support long doubles and allows them to be read in with  */
 /*   scanf(), but does not support the functions sinl, cosl, fabsl, etc.  */
 /* CAE added this 26Jan95 so it would compile (altered by Wes to new macro) */
-#ifdef _HPUX_SOURCE
+#if defined _HPUX_SOURCE || defined (__FreeBSD__)
 #define DO_NOT_USE_LONG_DOUBLE
 #endif
 
