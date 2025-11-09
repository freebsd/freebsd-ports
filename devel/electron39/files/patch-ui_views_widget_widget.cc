--- ui/views/widget/widget.cc.orig	2025-11-02 19:17:58 UTC
+++ ui/views/widget/widget.cc
@@ -64,7 +64,7 @@
 #include "ui/views/widget/widget_removals_observer.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2532,7 +2532,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
