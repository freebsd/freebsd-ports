--- extensions/common/features/feature.cc.orig	2019-09-10 10:42:38 UTC
+++ extensions/common/features/feature.cc
@@ -20,7 +20,7 @@ namespace extensions {
 Feature::Platform Feature::GetCurrentPlatform() {
 #if defined(OS_CHROMEOS)
   return CHROMEOS_PLATFORM;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return LINUX_PLATFORM;
 #elif defined(OS_MACOSX)
   return MACOSX_PLATFORM;
