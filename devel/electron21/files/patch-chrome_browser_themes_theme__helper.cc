--- chrome/browser/themes/theme_helper.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -18,7 +18,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -172,7 +172,7 @@ bool ThemeHelper::UseDarkModeColors(const CustomThemeS
 
   ui::NativeTheme const* native_theme =
       ui::NativeTheme::GetInstanceForNativeUi();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const auto* linux_ui = ui::LinuxUi::instance()) {
     // We rely on the fact that the system theme is in use iff `theme_supplier`
     // is non-null, but this is cheating. In the future this might not hold
