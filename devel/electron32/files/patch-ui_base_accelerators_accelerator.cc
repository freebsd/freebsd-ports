--- ui/base/accelerators/accelerator.cc.orig	2024-11-08 09:20:48 UTC
+++ ui/base/accelerators/accelerator.cc
@@ -419,6 +419,8 @@ std::u16string Accelerator::ApplyLongFormModifiers(
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SEARCH_KEY);
 #elif BUILDFLAG(IS_WIN)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_WINDOWS_KEY);
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+    result = ApplyModifierToAcceleratorString(result, IDS_APP_SUPER_KEY);
 #else
     NOTREACHED_IN_MIGRATION();
 #endif
