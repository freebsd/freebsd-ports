--- third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc.orig	2022-03-25 21:59:56 UTC
+++ third_party/blink/renderer/platform/fonts/font_unique_name_lookup.cc
@@ -9,7 +9,7 @@
 #if BUILDFLAG(IS_ANDROID)
 #include "third_party/blink/public/mojom/font_unique_name_lookup/font_unique_name_lookup.mojom-blink.h"
 #include "third_party/blink/renderer/platform/fonts/android/font_unique_name_lookup_android.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/linux/font_unique_name_lookup_linux.h"
 #elif BUILDFLAG(IS_WIN)
 #include "third_party/blink/renderer/platform/fonts/win/font_unique_name_lookup_win.h"
@@ -24,7 +24,7 @@ std::unique_ptr<FontUniqueNameLookup>
 FontUniqueNameLookup::GetPlatformUniqueNameLookup() {
 #if BUILDFLAG(IS_ANDROID)
   return std::make_unique<FontUniqueNameLookupAndroid>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<FontUniqueNameLookupLinux>();
 #elif BUILDFLAG(IS_WIN)
   return std::make_unique<FontUniqueNameLookupWin>();
