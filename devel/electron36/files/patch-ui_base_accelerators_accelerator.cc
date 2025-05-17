--- ui/base/accelerators/accelerator.cc.orig	2025-05-11 11:50:45 UTC
+++ ui/base/accelerators/accelerator.cc
@@ -346,7 +346,7 @@ std::u16string Accelerator::ApplyLongFormModifiers(
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SEARCH_KEY);
 #elif BUILDFLAG(IS_WIN)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_WINDOWS_KEY);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     result = ApplyModifierToAcceleratorString(result, IDS_APP_SUPER_KEY);
 #else
     NOTREACHED();
