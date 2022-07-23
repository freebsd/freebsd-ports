--- src/gui/sdl_gui.cpp.orig	2022-07-23 20:37:25 UTC
+++ src/gui/sdl_gui.cpp
@@ -3563,6 +3563,7 @@ void GUI_Shortcut(int select) {
     shortcutid=select;
     shortcut=true;
     sel = select;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse && !confres) {
         ttf_switch_off();
@@ -3572,12 +3573,14 @@ void GUI_Shortcut(int select) {
     } else
 #endif
     RunCfgTool(NULL);
+#endif
 }
 
 void GUI_Run(bool pressed) {
     if (pressed || running) return;
 
     sel = -1;
+#ifndef __FreeBSD__
 #if defined(USE_TTF)
     if (ttf.inUse) {
         ttf_switch_off();
@@ -3587,4 +3590,5 @@ void GUI_Run(bool pressed) {
     } else
 #endif
     RunCfgTool(NULL);
+#endif
 }
