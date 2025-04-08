--- ui/color/color_provider_utils.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/color/color_provider_utils.cc
@@ -189,7 +189,7 @@ std::string_view SystemThemeName(ui::SystemTheme syste
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
