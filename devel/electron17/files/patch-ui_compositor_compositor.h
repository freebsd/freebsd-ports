--- ui/compositor/compositor.h.orig	2022-05-13 07:19:54 UTC
+++ ui/compositor/compositor.h
@@ -402,7 +402,7 @@ class COMPOSITOR_EXPORT Compositor : public base::Powe
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
