--- libasync.c.orig	2015-10-20 14:12:13 UTC
+++ libasync.c
@@ -96,13 +96,13 @@
 
 #include <sys/types.h>
 #include <aio.h>
-#if defined(solaris) || defined(linux) || defined(SCO_Unixware_gcc) || defined(__NetBSD__)
+#if defined(solaris) || defined(linux) || defined(SCO_Unixware_gcc) || defined(__NetBSD__) || defined(__FreeBSD__)
 #else
 #include <sys/timers.h>
 #endif
 #include <sys/errno.h>
 #include <unistd.h>
-#ifndef bsd4_4
+#if !defined(bsd4_4) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #ifdef VXFS
@@ -119,7 +119,7 @@
 #include <stdlib.h>
 #endif
 
-#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(FreeBSD) || defined(__NetBSD__)
+#if (defined(solaris) && defined(__LP64__)) || defined(__s390x__) || defined(__FreeBSD__) || defined(__NetBSD__)
 /* If we are building for 64-bit Solaris, all functions that return pointers
  * must be declared before they are used; otherwise the compiler will assume
  * that they return ints and the top 32 bits of the pointer will be lost,
@@ -135,7 +135,7 @@
 void mbcopy(char *source, char *dest, size_t len);
 
 
-#if !defined(solaris) && !defined(off64_t) && !defined(_OFF64_T) && !defined(__off64_t_defined) && !defined(SCO_Unixware_gcc)
+#if !defined(solaris) && !defined(off64_t) && !defined(_OFF64_T) && !defined(__off64_t_defined) && !defined(SCO_Unixware_gcc) && !defined(__FreeBSD__)
 typedef long long off64_t;
 #endif
 #if defined(OSFV5)
