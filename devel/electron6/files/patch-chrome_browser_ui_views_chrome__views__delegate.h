--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2019-09-10 10:42:31 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -44,7 +44,7 @@ class ChromeViewsDelegate : public views::ViewsDelegat
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              base::OnceClosure callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
