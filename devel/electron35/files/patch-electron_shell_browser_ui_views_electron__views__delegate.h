--- electron/shell/browser/ui/views/electron_views_delegate.h.orig	2025-01-29 20:10:57 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.h
@@ -44,7 +44,7 @@ class ViewsDelegate : public views::ViewsDelegate {
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#elif (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
   std::unique_ptr<views::NonClientFrameView> CreateDefaultNonClientFrameView(
