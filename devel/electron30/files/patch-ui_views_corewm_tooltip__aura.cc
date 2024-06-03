--- ui/views/corewm/tooltip_aura.cc.orig	2024-04-15 20:34:30 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -36,7 +36,7 @@ bool CanUseTranslucentTooltipWidget() {
 bool CanUseTranslucentTooltipWidget() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
