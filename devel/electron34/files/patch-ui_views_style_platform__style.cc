--- ui/views/style/platform_style.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/views/style/platform_style.cc
@@ -16,7 +16,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 
@@ -49,7 +49,7 @@ const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 // Linux clips bubble windows that extend outside their parent window
 // bounds.
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
@@ -58,7 +58,7 @@ std::unique_ptr<ScrollBar> PlatformStyle::CreateScroll
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(
     ScrollBar::Orientation orientation) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(orientation);
 #else
   return std::make_unique<ScrollBarViews>(orientation);
