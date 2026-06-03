--- chrome/browser/browser_process_impl.h.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/browser_process_impl.h
@@ -422,7 +422,7 @@ class BrowserProcessImpl : public BrowserProcess,
 
   std::unique_ptr<BatteryMetrics> battery_metrics_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::RepeatingTimer autoupdate_timer_;
 
   // Gets called by autoupdate timer to see if browser needs restart and can be
