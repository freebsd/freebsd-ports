--- electron/shell/browser/osr/osr_host_display_client.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/osr/osr_host_display_client.cc
@@ -97,7 +97,7 @@ void OffScreenHostDisplayClient::CreateLayeredWindowUp
   layered_window_updater_->SetActive(active_);
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void OffScreenHostDisplayClient::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
