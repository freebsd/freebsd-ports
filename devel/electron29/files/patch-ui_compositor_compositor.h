--- ui/compositor/compositor.h.orig	2024-02-27 21:36:01 UTC
+++ ui/compositor/compositor.h
@@ -475,7 +475,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
