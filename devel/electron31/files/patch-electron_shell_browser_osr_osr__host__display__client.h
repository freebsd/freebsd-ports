--- electron/shell/browser/osr/osr_host_display_client.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/osr/osr_host_display_client.h
@@ -72,7 +72,7 @@ class OffScreenHostDisplayClient : public viz::HostDis
       mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
       override;
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
