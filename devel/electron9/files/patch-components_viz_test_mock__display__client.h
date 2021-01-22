--- components/viz/test/mock_display_client.h.orig	2020-05-26 08:03:23 UTC
+++ components/viz/test/mock_display_client.h
@@ -35,7 +35,7 @@ class MockDisplayClient : public mojom::DisplayClient 
   MOCK_METHOD1(OnContextCreationResult, void(gpu::ContextResult));
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif
 
