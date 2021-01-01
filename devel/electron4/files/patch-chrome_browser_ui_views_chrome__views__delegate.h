--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -43,7 +43,7 @@ class ChromeViewsDelegate : public views::ViewsDelegat
   HICON GetSmallWindowIcon() const override;
   int GetAppbarAutohideEdges(HMONITOR monitor,
                              const base::Closure& callback) override;
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
