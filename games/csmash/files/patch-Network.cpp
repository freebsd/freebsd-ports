--- Network.cpp.orig	Sun Aug 17 20:43:03 2003
+++ Network.cpp	Mon Nov 24 10:35:27 2003
@@ -36,13 +36,15 @@
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
 
@@ -169,7 +171,6 @@
 
   char *b = buf;
   long millitm;
-  b = ReadLong( b, tb->time );
   b = ReadLong( b, millitm );
   tb->millitm = (unsigned short)millitm;
 
