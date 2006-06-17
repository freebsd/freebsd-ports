--- ./net.h.orig	Sat Jun 10 12:08:13 2006
+++ ./net.h	Sat Jun 10 12:08:13 2006
@@ -239,7 +239,7 @@
 extern int hostCacheCount;
 extern hostcache_t hostcache[HOSTCACHESIZE];
 
-#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__)
+#if !defined(_WIN32 ) && !defined (__linux__) && !defined (__sun__) && !defined (__FreeBSD__)
 #ifndef htonl
 extern unsigned long htonl (unsigned long hostlong);
 #endif
