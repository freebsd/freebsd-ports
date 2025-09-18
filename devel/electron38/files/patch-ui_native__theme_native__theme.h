--- ui/native_theme/native_theme.h.orig	2025-02-02 01:39:08 UTC
+++ ui/native_theme/native_theme.h
@@ -61,7 +61,7 @@ class NATIVE_THEME_EXPORT NativeTheme {
   // The part to be painted / sized.
   enum Part {
     kCheckbox,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFrameTopArea,
 #endif
     kInnerSpinButton,
