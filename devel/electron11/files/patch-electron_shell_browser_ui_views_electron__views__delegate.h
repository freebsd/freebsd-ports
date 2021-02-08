--- electron/shell/browser/ui/views/electron_views_delegate.h.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.h
@@ -41,7 +41,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   std::unique_ptr<views::NonClientFrameView> CreateDefaultNonClientFrameView(
