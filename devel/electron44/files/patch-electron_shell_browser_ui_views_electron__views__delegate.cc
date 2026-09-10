--- electron/shell/browser/ui/views/electron_views_delegate.cc.orig	2026-08-31 00:54:19 UTC
+++ electron/shell/browser/ui/views/electron_views_delegate.cc
@@ -36,7 +36,7 @@ void ViewsDelegate::NotifyMenuItemFocused(const std::u
                                           int item_count,
                                           bool has_submenu) {}
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)) || BUILDFLAG(IS_BSD)
 gfx::ImageSkia* ViewsDelegate::GetDefaultWindowIcon() const {
   return nullptr;
 }
