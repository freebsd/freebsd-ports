--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2019-12-12 12:40:07 UTC
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -338,7 +338,7 @@ ScrollbarPart ScrollbarThemeAura::InvalidateOnThumbPos
 
 bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scrollbar& scrollbar,
                                              const WebMouseEvent& event) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
@@ -353,7 +353,7 @@ bool ScrollbarThemeAura::ShouldSnapBackToDragOrigin(
 // Disable snapback on desktop Linux to better integrate with the desktop
 // behavior.  Typically, Linux apps do not implement scrollbar snapback (this is
 // true for at least GTK and QT apps).
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return false;
 #endif
 
