--- include/unixconf.h.orig	2021-03-22 22:28:14 UTC
+++ include/unixconf.h
@@ -20,13 +20,13 @@
  */
 
 /* define exactly one of the following four choices */
-/* #define BSD 1 */  /* define for 4.n/Free/Open/Net BSD  */
+#define BSD 1        /* define for 4.n/Free/Open/Net BSD  */
                      /* also for relatives like SunOS 4.x, DG/UX, and */
                      /* older versions of Linux */
 /* #define ULTRIX */ /* define for Ultrix v3.0 or higher (but not lower) */
                      /* Use BSD for < v3.0 */
                      /* "ULTRIX" not to be confused with "ultrix" */
-#define SYSV         /* define for System V, Solaris 2.x, newer versions */
+/* #define SYSV */   /* define for System V, Solaris 2.x, newer versions */
                      /* of Linux */
 /* #define HPUX */   /* Hewlett-Packard's Unix, version 6.5 or higher */
                      /* use SYSV for < v6.5 */
@@ -315,7 +315,7 @@
 #endif
 
 #if defined(BSD) || defined(ULTRIX)
-#if !defined(DGUX) && !defined(SUNOS4)
+#if !defined(DGUX) && !defined(SUNOS4) && !defined(__FreeBSD__)
 #define memcpy(d, s, n) bcopy(s, d, n)
 #define memcmp(s1, s2, n) bcmp(s2, s1, n)
 #endif
