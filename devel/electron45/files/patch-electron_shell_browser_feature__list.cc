--- electron/shell/browser/feature_list.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/feature_list.cc
@@ -31,7 +31,7 @@
 #include "pdf/pdf_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -105,7 +105,7 @@ void InitializeFeatureList() {
       std::string(",") + chrome_pdf::features::kPdfUseShowSaveFilePicker.name;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Without this, globalShortcut is a silent no-op on GNOME Wayland (the
   // ozone factory returns no listener there). Chromium keeps it off due to
   // https://gitlab.gnome.org/GNOME/xdg-desktop-portal-gnome/-/issues/185,
