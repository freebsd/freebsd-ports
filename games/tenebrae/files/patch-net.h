--- net.h.orig	2020-09-30 11:25:10 UTC
+++ net.h
@@ -239,7 +239,7 @@ typedef struct
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__)
+#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__) && !defined (__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
