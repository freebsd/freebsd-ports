--- src/gui/sdl_gui.cpp.orig	2026-08-02 19:09:21 UTC
+++ src/gui/sdl_gui.cpp
@@ -4074,6 +4074,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -4083,12 +4084,14 @@ void GUI_Shortcut(int select) {
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
@@ -4098,4 +4101,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
