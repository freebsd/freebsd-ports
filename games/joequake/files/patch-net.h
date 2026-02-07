--- ./net.h.orig	Thu Jul 21 13:00:04 2005
+++ ./net.h	Sat May 20 10:00:24 2006
@@ -258,7 +258,7 @@
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__)
+#if !defined(_WIN32 ) && !defined (__linux__) && !defined(__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
