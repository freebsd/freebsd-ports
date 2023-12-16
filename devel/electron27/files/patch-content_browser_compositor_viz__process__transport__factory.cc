--- content/browser/compositor/viz_process_transport_factory.cc.orig	2023-10-25 09:13:44 UTC
+++ content/browser/compositor/viz_process_transport_factory.cc
@@ -108,7 +108,7 @@ class HostDisplayClient : public viz::HostDisplayClien
   // viz::HostDisplayClient:
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
