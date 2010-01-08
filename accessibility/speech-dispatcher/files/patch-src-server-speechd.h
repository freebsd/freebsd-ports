--- src/server/speechd.h.orig	2009-12-08 16:41:26.578943406 +0000
+++ src/server/speechd.h	2009-12-08 16:42:16.923002174 +0000
@@ -53,7 +53,7 @@
 #include <sys/sem.h>
 
 /* Definition of semun needed for semaphore manipulation */
-#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
+#if 1
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
