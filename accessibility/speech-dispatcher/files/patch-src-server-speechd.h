--- src/server/speechd.h.orig	2010-08-25 03:20:44.157056094 +0200
+++ src/server/speechd.h	2010-08-25 03:21:00.004912354 +0200
@@ -56,7 +56,7 @@
 /* TODO: This fixes compilation for Mac OS X but might not be a correct
    solution for other platforms. A better check is needed, possibly including
    _POSIX_C_SOURCE and friends*/
-#if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) || defined(__APPLE__)
+#if 1
  /* union semun is defined by including <sys/sem.h> */
 #else
  /* according to X/OPEN we have to define it ourselves */
