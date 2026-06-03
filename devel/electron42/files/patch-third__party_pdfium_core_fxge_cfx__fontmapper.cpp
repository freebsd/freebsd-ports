--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2026-04-28 21:06:17 UTC
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -159,7 +159,7 @@ constexpr AltFontFamily kAltFontFamilies[] = {
     {"ForteMT", "Forte"},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif BUILDFLAG(IS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";
