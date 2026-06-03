--- platform/linuxbsd/platform_config.h.orig	2025-10-13 19:05:40 UTC
+++ platform/linuxbsd/platform_config.h
@@ -30,18 +30,22 @@
 
 #pragma once
 
+// alloca
 #ifdef __linux__
 #include <alloca.h>
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#ifdef __cplusplus
+#include <cstdlib>
+#else
+#include <stdio.h>
 #endif
+#endif
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
-#include <cstdlib> // alloca
+#if defined(__FreeBSD__) || defined(__OpenBSD__)
 // FreeBSD and OpenBSD use pthread_set_name_np, while other platforms,
 // include NetBSD, use pthread_setname_np. NetBSD's version however requires
 // a different format, we handle this directly in thread_posix.
-#ifdef __NetBSD__
-#define PTHREAD_NETBSD_SET_NAME
-#else
 #define PTHREAD_BSD_SET_NAME
-#endif
+#elif defined(__NetBSD__)
+#define PTHREAD_NETBSD_SET_NAME
 #endif
