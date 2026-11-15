--- ui/views/views_delegate.h.orig	2026-03-13 16:54:03 UTC
+++ ui/views/views_delegate.h
@@ -139,7 +139,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
