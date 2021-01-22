--- components/viz/host/host_display_client.cc.orig	2020-05-28 04:23:53 UTC
+++ components/viz/host/host_display_client.cc
@@ -64,7 +64,7 @@ void HostDisplayClient::CreateLayeredWindowUpdater(
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
