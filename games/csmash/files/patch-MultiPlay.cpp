--- MultiPlay.cpp.orig	Thu Nov 20 02:05:02 2003
+++ MultiPlay.cpp	Mon Nov 24 09:34:22 2003
@@ -37,13 +37,15 @@
 #include <netinet/tcp.h>
 #endif
 
-#if defined(WIN32) || defined(__FreeBSD__)
+#if defined(WIN32)
 
 typedef int socklen_t;		/* mimic Penguin's typedef */
 
 #else	/* ! WIN32 */
 
+#if !defined(__FreeBSD__)
 #define closesocket(FD) close(FD)
+#endif
 
 #endif
 
