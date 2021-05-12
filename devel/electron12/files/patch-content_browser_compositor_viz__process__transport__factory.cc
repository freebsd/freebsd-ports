--- content/browser/compositor/viz_process_transport_factory.cc.orig	2021-04-22 07:51:51 UTC
+++ content/browser/compositor/viz_process_transport_factory.cc
@@ -111,7 +111,7 @@ class HostDisplayClient : public viz::HostDisplayClien
   // viz::HostDisplayClient:
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
