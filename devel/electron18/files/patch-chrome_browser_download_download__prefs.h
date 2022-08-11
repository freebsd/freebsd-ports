--- chrome/browser/download/download_prefs.h.orig	2022-05-19 05:17:36 UTC
+++ chrome/browser/download/download_prefs.h
@@ -122,7 +122,7 @@ class DownloadPrefs {
   void DisableAutoOpenByUserBasedOnExtension(const base::FilePath& file_name);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Store the user preference to disk. If |should_open| is true, also disable
   // the built-in PDF plugin. If |should_open| is false, enable the PDF plugin.
   void SetShouldOpenPdfInSystemReader(bool should_open);
@@ -181,7 +181,7 @@ class DownloadPrefs {
   std::unique_ptr<policy::URLBlocklist> auto_open_allowed_by_urls_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool should_open_pdf_in_system_reader_;
 #endif
 
