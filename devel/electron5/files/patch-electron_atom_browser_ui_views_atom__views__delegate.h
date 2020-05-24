--- electron/atom/browser/ui/views/atom_views_delegate.h.orig	2019-04-04 16:09:31 UTC
+++ electron/atom/browser/ui/views/atom_views_delegate.h
@@ -37,7 +37,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   HICON GetDefaultWindowIcon() const override;
   HICON GetSmallWindowIcon() const override;
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   views::NonClientFrameView* CreateDefaultNonClientFrameView(
