--- components/viz/test/fake_display_client.h.orig	2022-05-19 03:45:27 UTC
+++ components/viz/test/fake_display_client.h
@@ -34,7 +34,7 @@ class FakeDisplayClient : public mojom::DisplayClient 
       mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
