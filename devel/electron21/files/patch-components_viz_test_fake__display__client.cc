--- components/viz/test/fake_display_client.cc.orig	2022-02-28 16:54:41 UTC
+++ components/viz/test/fake_display_client.cc
@@ -25,7 +25,7 @@ void FakeDisplayClient::CreateLayeredWindowUpdater(
     mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void FakeDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {}
 #endif
 
