--- src/global.h.orig	Tue Sep  7 22:41:45 1999
+++ src/global.h	Mon Nov 22 17:03:53 2004
@@ -79,6 +79,14 @@
 
 #else	/* Not Linux */
 
+#if defined(__FreeBSD__)
+
+#ifndef FREEBSD
+#define FREEBSD	1
+#endif
+
+#else  /* Not FreeBSD */
+
 #if defined(sun) && defined(unix)
 
 #if defined(__svr4__) || defined(SVR4) || defined(SYSV)
@@ -106,6 +114,7 @@
 #endif  /* Not HP-UX */
 #endif  /* Not Solaris */
 #endif	/* Sun && Unix */
+#endif  /* Not FreeBSD */
 #endif	/* Not Linux */
 
 #ifdef SYSV
