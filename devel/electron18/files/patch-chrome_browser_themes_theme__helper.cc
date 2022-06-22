--- chrome/browser/themes/theme_helper.cc.orig	2022-05-19 05:17:38 UTC
+++ chrome/browser/themes/theme_helper.cc
@@ -297,7 +297,7 @@ bool ThemeHelper::ShouldUseIncreasedContrastThemeSuppl
     ui::NativeTheme* native_theme) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // On Linux the GTK system theme provides the high contrast colors,
   // so don't use the IncreasedContrastThemeSupplier.
   return false;
