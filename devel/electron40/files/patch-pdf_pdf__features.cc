--- pdf/pdf_features.cc.orig	2026-01-07 00:52:53 UTC
+++ pdf/pdf_features.cc
@@ -47,7 +47,7 @@ BASE_FEATURE(kPdfXfaSupport, base::FEATURE_DISABLED_BY
 // Feature has no effect if Chrome is built with no XFA support.
 BASE_FEATURE(kPdfXfaSupport, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables PDFium's version 2 font mapping interface, which uses per-request
 // font matching instead of enumerating all fonts upfront. This eliminates the
 // need for the ListFamilies() IPC call and improves PDF load performance on
