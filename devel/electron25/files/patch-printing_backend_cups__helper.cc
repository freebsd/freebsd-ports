--- printing/backend/cups_helper.cc.orig	2023-03-30 00:33:55 UTC
+++ printing/backend/cups_helper.cc
@@ -127,7 +127,7 @@ void GetResolutionSettings(ppd_file_t* ppd,
   // found.
 #if BUILDFLAG(IS_MAC)
   constexpr gfx::Size kDefaultMissingDpi(kDefaultMacDpi, kDefaultMacDpi);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   constexpr gfx::Size kDefaultMissingDpi(kPixelsPerInch, kPixelsPerInch);
 #else
   constexpr gfx::Size kDefaultMissingDpi(kDefaultPdfDpi, kDefaultPdfDpi);
