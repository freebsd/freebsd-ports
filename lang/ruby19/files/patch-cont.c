--- cont.c.orig	2012-02-16 22:31:17.691397569 -0500
+++ cont.c	2012-02-16 22:31:31.507395417 -0500
@@ -15,7 +15,7 @@
 #include "gc.h"
 #include "eval_intern.h"
 
-#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || (defined(HAVE_GETCONTEXT) && defined(HAVE_SETCONTEXT))) && !defined(__NetBSD__) && !defined(sun) && !defined(FIBER_USE_NATIVE)
+#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || (defined(HAVE_GETCONTEXT) && defined(HAVE_SETCONTEXT))) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(sun) && !defined(FIBER_USE_NATIVE)
 #define FIBER_USE_NATIVE 1
 
 /* FIBER_USE_NATIVE enables Fiber performance improvement using system
