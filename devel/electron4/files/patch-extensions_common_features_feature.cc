--- extensions/common/features/feature.cc.orig	2019-03-15 06:25:45 UTC
+++ extensions/common/features/feature.cc
@@ -26,6 +26,8 @@ Feature::Platform Feature::GetCurrentPlatform() {
   return MACOSX_PLATFORM;
 #elif defined(OS_WIN)
   return WIN_PLATFORM;
+#elif defined(OS_BSD)
+  return LINUX_PLATFORM;
 #else
   return UNSPECIFIED_PLATFORM;
 #endif
