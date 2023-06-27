--- components/viz/test/mock_display_client.h.orig	2023-02-01 18:43:18 UTC
+++ components/viz/test/mock_display_client.h
@@ -45,7 +45,7 @@ class MockDisplayClient : public mojom::DisplayClient 
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif
 
