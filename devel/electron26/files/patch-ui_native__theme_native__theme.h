--- ui/native_theme/native_theme.h.orig	2023-06-07 04:52:05 UTC
+++ ui/native_theme/native_theme.h
@@ -60,7 +60,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
     kCheckbox,
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
