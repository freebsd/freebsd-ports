
$FreeBSD$

--- modules/ipc/ipc_header.h.orig	Wed Jan  9 08:46:18 2002
+++ modules/ipc/ipc_header.h	Wed Jan  9 11:49:17 2002
@@ -22,7 +22,7 @@
 #define DEFAULT_SEGMENT_SIZE 1024
 
 
-#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
+#if defined(__FreeBSD__) || defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
     /* union semun is defined by including <sys/sem.h> */
 #else
    /* according to X/OPEN we have to define it ourselves */
