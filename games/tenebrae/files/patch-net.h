--- net.h.orig	Wed Mar 17 10:25:22 2004
+++ net.h	Wed Mar 17 10:25:37 2004
@@ -239,7 +239,7 @@
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__)
+#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__) && !defined (__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
