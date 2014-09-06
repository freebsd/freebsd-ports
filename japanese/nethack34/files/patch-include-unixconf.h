--- include/unixconf.h.orig	2014-08-28 14:59:56.000000000 +0900
+++ include/unixconf.h	2014-08-28 15:23:59.000000000 +0900
@@ -19,7 +19,7 @@
  */
 
 /* define exactly one of the following four choices */
-/* #define BSD 1 */	/* define for 4.n/Free/Open/Net BSD  */
+#define BSD 1		/* define for 4.n/Free/Open/Net BSD  */
 			/* also for relatives like SunOS 4.x, DG/UX, and */
 			/* older versions of Linux */
 /* #define ULTRIX */	/* define for Ultrix v3.0 or higher (but not lower) */
@@ -284,7 +284,7 @@
 #endif
 
 #if defined(BSD) || defined(ULTRIX)
-# if !defined(DGUX) && !defined(SUNOS4)
+# if !defined(DGUX) && !defined(SUNOS4) && !defined(__FreeBSD__)
 #define memcpy(d, s, n)		bcopy(s, d, n)
 #define memcmp(s1, s2, n)	bcmp(s2, s1, n)
 # endif
