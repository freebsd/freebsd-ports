--- ui/views/corewm/tooltip_aura.cc.orig	2024-10-16 21:32:40 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -37,7 +37,7 @@ bool CanUseTranslucentTooltipWidget() {
 bool CanUseTranslucentTooltipWidget() {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
