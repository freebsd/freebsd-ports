--- ui/compositor/compositor.h.orig	2026-09-01 23:50:56 UTC
+++ ui/compositor/compositor.h
@@ -464,7 +464,7 @@ class COMPOSITOR_EXPORT Compositor
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
