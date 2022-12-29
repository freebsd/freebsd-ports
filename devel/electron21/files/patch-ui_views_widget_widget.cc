--- ui/views/widget/widget.cc.orig	2022-08-31 12:19:35 UTC
+++ ui/views/widget/widget.cc
@@ -48,7 +48,7 @@
 #include "ui/views/window/custom_frame_view.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -1819,7 +1819,7 @@ const ui::NativeTheme* Widget::GetNativeTheme() const 
   if (parent_)
     return parent_->GetNativeTheme();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const ui::LinuxUi* linux_ui = ui::LinuxUi::instance()) {
     if (auto* native_theme = linux_ui->GetNativeTheme(GetNativeWindow()))
       return native_theme;
