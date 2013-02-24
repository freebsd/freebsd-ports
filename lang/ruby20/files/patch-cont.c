--- cont.c.orig	2013-01-30 04:17:59.000000000 +0000
+++ cont.c	2013-02-17 21:39:30.712834241 +0000
@@ -15,7 +15,7 @@
 #include "gc.h"
 #include "eval_intern.h"
 
-#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || (defined(HAVE_GETCONTEXT) && defined(HAVE_SETCONTEXT))) && !defined(__NetBSD__) && !defined(__sun) && !defined(__ia64) && !defined(FIBER_USE_NATIVE)
+#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || (defined(HAVE_GETCONTEXT) && defined(HAVE_SETCONTEXT))) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__sun) && !defined(__ia64) && !defined(FIBER_USE_NATIVE)
 #define FIBER_USE_NATIVE 1
 
 /* FIBER_USE_NATIVE enables Fiber performance improvement using system
