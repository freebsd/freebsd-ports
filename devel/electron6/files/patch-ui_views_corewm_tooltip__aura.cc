--- ui/views/corewm/tooltip_aura.cc.orig	2019-09-10 11:14:40 UTC
+++ ui/views/corewm/tooltip_aura.cc
@@ -35,7 +35,7 @@ constexpr int kCursorOffsetY = 15;
 
 // TODO(varkha): Update if native widget can be transparent on Linux.
 bool CanUseTranslucentTooltipWidget() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   return false;
 #else
   return true;
