--- cont.c.orig	2011-11-18 03:37:32.000000000 -0800
+++ cont.c	2011-11-18 03:38:22.000000000 -0800
@@ -15,7 +15,7 @@
 #include "gc.h"
 #include "eval_intern.h"
 
-#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || defined(HAVE_SETCONTEXT)) && !defined(__NetBSD__) && !defined(sun) && !defined(FIBER_USE_NATIVE)
+#if ((defined(_WIN32) && _WIN32_WINNT >= 0x0400) || defined(HAVE_SETCONTEXT)) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(sun) && !defined(FIBER_USE_NATIVE)
 #define FIBER_USE_NATIVE 1
 
 /* FIBER_USE_NATIVE enables Fiber performance improvement using system
