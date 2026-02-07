--- src/internal.h.orig	Mon May  6 22:38:42 2002
+++ src/internal.h	Mon May  6 22:40:33 2002
@@ -72,7 +72,7 @@
     pthread_t thread;
 };
 
-#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
+#if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED) || defined(__FreeBSD__))
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
