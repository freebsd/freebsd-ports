--- headers/port.h.orig	2015-07-04 13:09:32 UTC
+++ headers/port.h
@@ -44,7 +44,7 @@
 /* If endian.h is not present, it can be handled in the code below, */
 /* but if you have this file, it can make it more fool proof. */
 #if (defined(XFRACT) && !defined(__sun))
-#if defined(sgi)
+#if defined(sgi) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
@@ -333,7 +333,7 @@ extern struct DIR_SEARCH DTA;   /* Disk Transfer Area 
 /* HP-UX support long doubles and allows them to be read in with  */
 /*   scanf(), but does not support the functions sinl, cosl, fabsl, etc.  */
 /* CAE added this 26Jan95 so it would compile (altered by Wes to new macro) */
-#ifdef _HPUX_SOURCE
+#if defined _HPUX_SOURCE || defined (__FreeBSD__)
 #define DO_NOT_USE_LONG_DOUBLE
 #endif
 
