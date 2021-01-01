--- third_party/pdfium/core/fxcrt/fx_system.h.orig	2019-09-10 11:17:33 UTC
+++ third_party/pdfium/core/fxcrt/fx_system.h
@@ -26,7 +26,7 @@
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
 #elif defined(_WIN64)
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define _FX_PLATFORM_ _FX_PLATFORM_LINUX_
 #elif defined(__APPLE__)
 #define _FX_PLATFORM_ _FX_PLATFORM_APPLE_
