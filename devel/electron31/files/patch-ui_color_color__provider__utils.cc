--- ui/color/color_provider_utils.cc.orig	2024-06-18 21:44:02 UTC
+++ ui/color/color_provider_utils.cc
@@ -186,7 +186,7 @@ std::string_view SystemThemeName(ui::SystemTheme syste
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
