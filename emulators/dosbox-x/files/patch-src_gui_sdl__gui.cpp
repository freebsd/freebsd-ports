--- src/gui/sdl_gui.cpp.orig	2025-10-07 15:49:14 UTC
+++ src/gui/sdl_gui.cpp
@@ -3886,6 +3886,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -3895,12 +3896,14 @@ void GUI_Shortcut(int select) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
 
 void GUI_Run(bool pressed) {
     if (pressed || running) return;
 
     sel = -1;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse) {
         ttf_switch_off();
@@ -3910,4 +3913,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
