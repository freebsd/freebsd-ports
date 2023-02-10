--- src/gui/sdl_gui.cpp.orig	2022-12-27 02:28:50 UTC
+++ src/gui/sdl_gui.cpp
@@ -3646,6 +3646,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -3655,12 +3656,14 @@ void GUI_Shortcut(int select) {
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
@@ -3670,4 +3673,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(0);
+#endif
 }
