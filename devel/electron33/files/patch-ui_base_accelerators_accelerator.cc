--- ui/base/accelerators/accelerator.cc.orig	2024-11-11 11:18:33 UTC
+++ ui/base/accelerators/accelerator.cc
@@ -419,7 +419,7 @@ std::u16string Accelerator::ApplyLongFormModifiers(
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SEARCH_KEY);
 #elif BUILDFLAG(IS_WIN)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_WINDOWS_KEY);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SUPER_KEY);
 #else
     NOTREACHED();
