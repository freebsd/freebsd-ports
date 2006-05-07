--- net.h.orig	Thu Jul 21 12:00:04 2005
+++ net.h	Mon Dec  5 21:11:16 2005
@@ -258,7 +258,7 @@
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__)
+#if !defined(_WIN32 ) && !defined (__linux__) && !defined(__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
