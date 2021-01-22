--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2020-05-18 21:17:08 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -101,7 +101,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
