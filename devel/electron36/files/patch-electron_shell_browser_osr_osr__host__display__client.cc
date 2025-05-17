--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -95,7 +95,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
