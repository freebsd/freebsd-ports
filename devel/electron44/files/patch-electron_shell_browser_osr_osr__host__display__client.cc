--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2026-04-15 14:10:25 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -102,7 +102,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
