--- ui/views/corewm/tooltip_aura.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -42,7 +42,7 @@ bool CanUseTranslucentTooltipWidget() {
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
