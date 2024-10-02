--- src/gui/sdl_gui.cpp.orig	2024-10-02 06:16:36 UTC
+++ src/gui/sdl_gui.cpp
@@ -3888,6 +3888,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -3897,12 +3898,14 @@ void GUI_Shortcut(int select) {
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
@@ -3912,4 +3915,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
