--- ui/views/widget/widget.cc.orig	2026-09-01 23:50:56 UTC
+++ ui/views/widget/widget.cc
@@ -72,7 +72,7 @@
 #include "ui/views/window/dialog_delegate.h"
 #include "ui/wm/core/window_properties.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2772,7 +2772,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
