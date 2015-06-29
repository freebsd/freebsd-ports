--- src/server/speechd.h.orig	2015-06-04 01:52:14 UTC
+++ src/server/speechd.h
@@ -56,7 +56,7 @@
 /* TODO: This fixes compilation for Mac OS X but might not be a correct
    solution for other platforms. A better check is needed, possibly including
    _POSIX_C_SOURCE and friends*/
-#if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) || defined(__APPLE__)
+#if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) || defined(__APPLE__) || defined(__FreeBSD__)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
