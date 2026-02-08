--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -94,7 +94,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
