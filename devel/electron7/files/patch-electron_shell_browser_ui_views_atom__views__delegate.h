--- electron/shell/browser/ui/views/atom_views_delegate.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/ui/views/atom_views_delegate.h
@@ -40,7 +40,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   bool IsWindowInMetro(gfx::NativeWindow window) const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   views::NonClientFrameView* CreateDefaultNonClientFrameView(
