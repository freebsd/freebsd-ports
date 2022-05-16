--- ui/gfx/switches.h.orig	2022-05-13 07:19:54 UTC
+++ ui/gfx/switches.h
@@ -19,7 +19,7 @@ GFX_SWITCHES_EXPORT extern const char kEnableNativeGpu
 GFX_SWITCHES_EXPORT extern const char kForcePrefersReducedMotion[];
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
