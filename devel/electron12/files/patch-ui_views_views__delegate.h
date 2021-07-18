--- ui/views/views_delegate.h.orig	2021-04-14 01:09:40 UTC
+++ ui/views/views_delegate.h
@@ -138,7 +138,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
