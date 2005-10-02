--- Modules/socketmodule.c.orig	Sun Oct  2 21:49:22 2005
+++ Modules/socketmodule.c	Sun Oct  2 21:50:01 2005
@@ -142,7 +142,9 @@
 
 /* On systems on which getaddrinfo() is believed to not be thread-safe,
    (this includes the getaddrinfo emulation) protect access with a lock. */
-#if defined(WITH_THREAD) && (defined(__APPLE__) || defined(__FreeBSD__) || \
+#include <sys/param.h>
+#if defined(WITH_THREAD) && (defined(__APPLE__) || \
+    (defined(__FreeBSD__) && __FreeBSD_version+0 < 503000) || \
     defined(__OpenBSD__) || defined(__NetBSD__) || !defined(HAVE_GETADDRINFO))
 #define USE_GETADDRINFO_LOCK
 #endif
