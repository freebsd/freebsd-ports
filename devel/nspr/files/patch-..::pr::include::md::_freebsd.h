
$FreeBSD$

--- ../pr/include/md/_freebsd.h.orig	Wed Jun 21 00:22:19 2000
+++ ../pr/include/md/_freebsd.h	Tue Dec 18 11:24:06 2001
@@ -37,6 +37,7 @@
 
 #include "prthread.h"
 
+#include <sys/param.h>
 #include <sys/syscall.h>
 
 #define PR_LINKER_ARCH	"freebsd"
@@ -65,7 +66,7 @@
 #define _PR_HAVE_SOCKADDR_LEN
 #define _PR_STAT_HAS_ST_ATIMESPEC
 #define _PR_NO_LARGE_FILES
-#if ( __FreeBSD__ > 2 )
+#if ( __FreeBSD_version >= 220000 ) && ( __FreeBSD_version < 400008 )
 #if !defined(_PR_PTHREADS)
 /*
  * libc_r doesn't have poll().  Although libc has poll(), it is not
