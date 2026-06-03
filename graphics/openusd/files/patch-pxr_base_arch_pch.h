--- pxr/base/arch/pch.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/pch.h
@@ -30,7 +30,7 @@
 #include <mach-o/swap.h>
 #include <mach/mach_time.h>
 #endif
-#if defined(ARCH_OS_LINUX)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD)
 #include <chrono>
 #include <dlfcn.h>
 #include <glob.h>
