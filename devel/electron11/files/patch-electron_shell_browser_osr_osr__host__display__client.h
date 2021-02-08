--- electron/shell/browser/osr/osr_host_display_client.h.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/osr/osr_host_display_client.h
@@ -66,7 +66,7 @@ class OffScreenHostDisplayClient : public viz::HostDis
       mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
       override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
