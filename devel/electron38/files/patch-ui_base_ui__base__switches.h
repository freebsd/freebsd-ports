--- ui/base/ui_base_switches.h.orig	2025-06-30 07:04:30 UTC
+++ ui/base/ui_base_switches.h
@@ -22,11 +22,11 @@ COMPONENT_EXPORT(UI_BASE) extern const char kShowMacOv
 COMPONENT_EXPORT(UI_BASE) extern const char kShowMacOverlayBorders[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kSystemFontFamily[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kUiToolkitFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kGtkVersionFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kQtVersionFlag[];
