--- ui/views/views_delegate.cc.orig	2021-11-19 04:25:48 UTC
+++ ui/views/views_delegate.cc
@@ -95,7 +95,7 @@ bool ViewsDelegate::IsWindowInMetro(gfx::NativeWindow 
   return false;
 }
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
