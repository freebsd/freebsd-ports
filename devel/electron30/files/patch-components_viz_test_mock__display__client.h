--- components/viz/test/mock_display_client.h.orig	2024-02-21 00:20:44 UTC
+++ components/viz/test/mock_display_client.h
@@ -43,7 +43,7 @@ class MockDisplayClient : public mojom::DisplayClient 
   MOCK_METHOD1(SetWideColorEnabled, void(bool enabled));
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
