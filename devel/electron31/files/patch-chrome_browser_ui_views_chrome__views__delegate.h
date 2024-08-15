--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -59,11 +59,11 @@ class ChromeViewsDelegate : public views::ViewsDelegat
                              base::OnceClosure callback) override;
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
