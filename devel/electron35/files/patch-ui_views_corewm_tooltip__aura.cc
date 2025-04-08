--- ui/views/corewm/tooltip_aura.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -38,7 +38,7 @@ bool CanUseTranslucentTooltipWidget() {
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
