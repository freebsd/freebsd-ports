--- components/viz/host/host_display_client.h.orig	2022-05-20 04:30:53 UTC
+++ components/viz/host/host_display_client.h
@@ -47,7 +47,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
