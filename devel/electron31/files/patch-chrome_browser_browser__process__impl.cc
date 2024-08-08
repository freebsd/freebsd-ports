--- chrome/browser/browser_process_impl.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -229,7 +229,7 @@
 #include "chrome/browser/ui/profiles/profile_picker.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/error_reporting/chrome_js_error_report_processor.h"  // nogncheck
 #endif
 
@@ -1284,7 +1284,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
 
   ApplyMetricsReportingPolicy();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChromeJsErrorReportProcessor::Create();
 #endif
 
@@ -1617,7 +1617,7 @@ void BrowserProcessImpl::Unpin() {
 // Mac is currently not supported.
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
