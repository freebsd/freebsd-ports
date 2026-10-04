--- src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/ze/utils.hpp.orig	2026-04-10 07:42:00 UTC
+++ src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/ze/utils.hpp
@@ -17,7 +17,7 @@
 #ifndef XPU_ZE_UTILS_HPP
 #define XPU_ZE_UTILS_HPP
 
-#if defined(__linux__)
+#if defined(__FreeBSD__)
 #include <dlfcn.h>
 #elif defined(_WIN32)
 #include "windows.h"
@@ -97,7 +97,7 @@ status_t ze_initialize();
 
 #if defined(_WIN32)
 #define ZE_LIB_NAME "ze_loader.dll"
-#elif defined(__linux__)
+#elif defined(__FreeBSD__)
 #define ZE_LIB_NAME "libze_loader.so.1"
 #endif
 
