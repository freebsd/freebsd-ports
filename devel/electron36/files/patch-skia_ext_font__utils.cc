--- skia/ext/font_utils.cc.orig	2025-04-22 20:15:27 UTC
+++ skia/ext/font_utils.cc
@@ -21,7 +21,7 @@
 #include "third_party/skia/include/ports/SkFontMgr_mac_ct.h"
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontMgr_FontConfigInterface.h"
 #include "third_party/skia/include/ports/SkFontScanner_Fontations.h"
@@ -67,7 +67,7 @@ static sk_sp<SkFontMgr> fontmgr_factory() {
   }
 #elif BUILDFLAG(IS_APPLE)
   return SkFontMgr_New_CoreText(nullptr);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   sk_sp<SkFontConfigInterface> fci(SkFontConfigInterface::RefGlobal());
   if (base::FeatureList::IsEnabled(skia::kFontationsLinuxSystemFonts)) {
     return fci ? SkFontMgr_New_FCI(std::move(fci),
