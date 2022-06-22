--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -97,7 +97,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
