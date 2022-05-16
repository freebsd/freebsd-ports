--- electron/shell/browser/osr/osr_host_display_client.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/osr/osr_host_display_client.h
@@ -72,7 +72,7 @@ class OffScreenHostDisplayClient : public viz::HostDis
       mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
       override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
