--- ui/views/style/platform_style.cc.orig	2023-02-01 18:43:52 UTC
+++ ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 
@@ -50,7 +50,7 @@ const View::FocusBehavior PlatformStyle::kDefaultFocus
 // Linux clips bubble windows that extend outside their parent window
 // bounds.
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
@@ -58,7 +58,7 @@ const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(bool is_horizontal) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(is_horizontal);
 #else
   return std::make_unique<ScrollBarViews>(is_horizontal);
