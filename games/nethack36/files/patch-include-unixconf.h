--- include/unixconf.h.orig	2015-11-17 10:54:25 UTC
+++ include/unixconf.h
@@ -19,13 +19,13 @@
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
@@ -46,7 +46,7 @@
                         * job control (note that AIX is SYSV otherwise)
                         * Also define this for AIX 3.2 */
 
-#define TERMINFO       /* uses terminfo rather than termcap */
+/* #define TERMINFO */ /* uses terminfo rather than termcap */
                        /* Should be defined for most SYSV, SVR4 (including
                         * Solaris 2+), HPUX, and Linux systems.  In
                         * particular, it should NOT be defined for the UNIXPC
@@ -297,7 +297,7 @@
 #endif
 
 #if defined(BSD) || defined(ULTRIX)
-#if !defined(DGUX) && !defined(SUNOS4)
+#if !defined(DGUX) && !defined(SUNOS4) && !defined(__FreeBSD__)
 #define memcpy(d, s, n) bcopy(s, d, n)
 #define memcmp(s1, s2, n) bcmp(s2, s1, n)
 #endif
