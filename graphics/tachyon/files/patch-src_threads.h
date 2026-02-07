--- src/threads.h.orig	2009-04-22 15:43:14 UTC
+++ src/threads.h
@@ -13,7 +13,7 @@
 #endif
 
 /* POSIX Threads */
-#if defined(HPUX) || defined(__PARAGON__) || defined(Irix) || defined(Linux) ||     defined(_CRAY) || defined(__osf__) || defined(AIX) || defined(__APPLE__)
+#if defined(HPUX) || defined(__PARAGON__) || defined(Irix) || defined(Linux) || defined(Bsd) || defined(_CRAY) || defined(__osf__) || defined(AIX) || defined(__APPLE__)
 #if !defined(USEUITHREADS) && !defined(USEPOSIXTHREADS)
 #define USEPOSIXTHREADS
 #endif
