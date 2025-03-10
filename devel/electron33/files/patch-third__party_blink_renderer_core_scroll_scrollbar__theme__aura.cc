--- third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc.orig	2024-10-16 21:31:45 UTC
+++ third_party/blink/renderer/core/scroll/scrollbar_theme_aura.cc
@@ -148,7 +148,7 @@ bool ScrollbarThemeAura::SupportsDragSnapBack() const 
 // is true for at least GTK and QT apps).
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
@@ -418,7 +418,7 @@ bool ScrollbarThemeAura::ShouldCenterOnThumb(const Scr
                                              const WebMouseEvent& event) const {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   if (event.button == WebPointerProperties::Button::kMiddle)
     return true;
 #endif
