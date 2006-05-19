--- ./src/net.h.orig	Tue Sep 27 12:45:44 2005
+++ ./src/net.h	Tue May 16 17:36:22 2006
@@ -238,7 +238,7 @@
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__)
+#if !defined(_WIN32 ) && !defined (__unix__) && !defined (__sun__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
