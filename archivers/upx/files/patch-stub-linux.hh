--- stub/linux.hh.orig	Tue Feb 17 01:31:35 2004
+++ stub/linux.hh	Tue Feb 17 07:30:02 2004
@@ -26,8 +26,8 @@
  */
 
 
-#if !defined(__linux__) || !defined(__i386__)
-#  error "this stub must be compiled under linux/i386"
+#if (!defined(__linux__) || !defined(__i386__)) && !defined(__FreeBSD__)
+#  error "this stub must be compiled under linux/i386 or FreeBSD"
 #endif
 
 
@@ -35,6 +35,16 @@
 // includes
 **************************************************************************/
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/mman.h>
+#include <sys/time.h>
+#include <sys/wait.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <time.h>
+#include <unistd.h>
+#else
 struct timex;
 
 #define __need_timeval
@@ -54,6 +64,7 @@
 
 #define CONST_CAST(type, var) \
     ((type) ((unsigned long) (var)))
+#endif
 
 
 /*************************************************************************
@@ -122,6 +133,7 @@
 #define PAGE_SIZE   ( 1u<<12)
 
 
+#if !defined(__FreeBSD__)
 /*************************************************************************
 // syscalls
 //
@@ -312,6 +324,7 @@
 
 #undef Z0
 #undef Z1
+#endif
 
 
 /*
