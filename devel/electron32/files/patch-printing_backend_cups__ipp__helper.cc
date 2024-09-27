--- printing/backend/cups_ipp_helper.cc.orig	2024-06-18 21:43:37 UTC
+++ printing/backend/cups_ipp_helper.cc
@@ -202,7 +202,7 @@ void ExtractResolutions(const CupsOptionProvider& prin
   // Provide a default DPI if no valid DPI is found.
 #if BUILDFLAG(IS_MAC)
   constexpr gfx::Size kDefaultMissingDpi(kDefaultMacDpi, kDefaultMacDpi);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   constexpr gfx::Size kDefaultMissingDpi(kPixelsPerInch, kPixelsPerInch);
 #else
   constexpr gfx::Size kDefaultMissingDpi(kDefaultPdfDpi, kDefaultPdfDpi);
