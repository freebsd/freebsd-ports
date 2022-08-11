--- ui/color/color_id.h.orig	2022-05-20 04:30:53 UTC
+++ ui/color/color_id.h
@@ -196,7 +196,7 @@
   E_CPONLY(kColorNativeColor6) \
   E_CPONLY(kColorNativeBaseColor) \
   E_CPONLY(kColorNativeSecondaryColor)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeButtonBackground) \
   E_CPONLY(kColorNativeButtonBackgroundDisabled) \
