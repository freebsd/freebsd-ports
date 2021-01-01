--- electron/brightray/browser/views/views_delegate.h.orig	2019-03-16 12:06:26 UTC
+++ electron/brightray/browser/views/views_delegate.h
@@ -39,7 +39,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   HICON GetDefaultWindowIcon() const override;
   HICON GetSmallWindowIcon() const override;
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   views::NonClientFrameView* CreateDefaultNonClientFrameView(
