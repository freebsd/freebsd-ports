--- src/gui/sdl_gui.cpp.orig	2026-10-02 02:13:17 UTC
+++ src/gui/sdl_gui.cpp
@@ -4088,6 +4088,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -4097,12 +4098,14 @@ void GUI_Shortcut(int select) {
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
@@ -4112,4 +4115,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
