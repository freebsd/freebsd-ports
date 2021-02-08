--- components/viz/host/host_display_client.h.orig	2021-01-25 11:27:00 UTC
+++ components/viz/host/host_display_client.h
@@ -43,7 +43,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
   void CreateLayeredWindowUpdater(
       mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
