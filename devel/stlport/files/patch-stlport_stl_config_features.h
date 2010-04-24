--- stlport/stl/config/features.h.orig	2007-08-18 22:45:42.000000000 +0200
+++ stlport/stl/config/features.h	2010-04-24 20:43:17.000000000 +0200
@@ -174,7 +174,8 @@
 
 #if !defined (_STLP_BIG_ENDIAN) && !defined (_STLP_LITTLE_ENDIAN)
 #  if defined (_MIPSEB) || defined (__sparc) || defined (_AIX) || \
-      defined (__hpux) || defined (macintosh) || defined (_MAC)
+      defined (__hpux) || defined (macintosh) || defined (_MAC) || \
+      defined (__powerpc__)
 #    define _STLP_BIG_ENDIAN 1
 #  elif defined (__i386) || defined (_M_IX86) || defined (_M_ARM) || \
         defined (__amd64__) || defined (_M_AMD64) || defined (__x86_64__) || \
@@ -218,7 +219,7 @@
 #endif
 
 /* Operating system recognition (basic) */
-#if defined (__unix) || defined (__linux__) || defined (__QNX__) || defined (_AIX)  || defined (__NetBSD__) || defined(__OpenBSD__) || defined (__Lynx__)
+#if defined (__unix) || defined (__linux__) || defined (__QNX__) || defined (_AIX)  || defined (__NetBSD__) || defined(__OpenBSD__) || defined (__Lynx__) || defined(__FreeBSD__)
 #  define _STLP_UNIX 1
 #elif defined(macintosh) || defined (_MAC)
 #  define _STLP_MAC  1
@@ -305,6 +306,7 @@
 #endif
 
 #if (defined (_REENTRANT) || defined (_THREAD_SAFE) || \
+    (defined (_POSIX_THREADS) && defined (__FreeBSD__)) && \
     (defined (_POSIX_THREADS) && defined (__OpenBSD__))) && \
     !defined (_STLP_THREADS)
 #  define _STLP_THREADS
