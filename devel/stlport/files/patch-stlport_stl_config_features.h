--- ./stlport/stl/config/features.h.orig	2007-08-18 22:45:42.000000000 +0200
+++ ./stlport/stl/config/features.h	2007-12-23 11:18:22.000000000 +0100
@@ -218,7 +218,7 @@
 #endif
 
 /* Operating system recognition (basic) */
-#if defined (__unix) || defined (__linux__) || defined (__QNX__) || defined (_AIX)  || defined (__NetBSD__) || defined(__OpenBSD__) || defined (__Lynx__)
+#if defined (__unix) || defined (__linux__) || defined (__QNX__) || defined (_AIX)  || defined (__NetBSD__) || defined(__OpenBSD__) || defined (__Lynx__) || defined(__FreeBSD__)
 #  define _STLP_UNIX 1
 #elif defined(macintosh) || defined (_MAC)
 #  define _STLP_MAC  1
@@ -305,6 +305,7 @@
 #endif
 
 #if (defined (_REENTRANT) || defined (_THREAD_SAFE) || \
+    (defined (_POSIX_THREADS) && defined (__FreeBSD__)) && \
     (defined (_POSIX_THREADS) && defined (__OpenBSD__))) && \
     !defined (_STLP_THREADS)
 #  define _STLP_THREADS
