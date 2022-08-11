--- electron/shell/browser/ui/views/electron_views_delegate.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.h
@@ -45,7 +45,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   std::unique_ptr<views::NonClientFrameView> CreateDefaultNonClientFrameView(
