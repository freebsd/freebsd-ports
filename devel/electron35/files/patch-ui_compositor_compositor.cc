--- ui/compositor/compositor.cc.orig	2025-04-06 11:53:46 UTC
+++ ui/compositor/compositor.cc
@@ -932,7 +932,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   observer_list_.Notify(
       &CompositorObserver::OnCompositingCompleteSwapWithNewSize, this, size);
