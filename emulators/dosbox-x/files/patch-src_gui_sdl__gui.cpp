--- src/gui/sdl_gui.cpp.orig	2022-04-21 18:01:44 UTC
+++ src/gui/sdl_gui.cpp
@@ -3022,7 +3022,7 @@ class ConfigurationWindow : public GUI::ToplevelWindow
             std::string url = "https://dosbox-x.com/";
 #if defined(WIN32)
             ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(__FreeBSD__)
             system(("xdg-open "+url).c_str());
 #elif defined(MACOSX)
             system(("open "+url).c_str());
@@ -3436,7 +3436,7 @@ void GUI_Shortcut(int select) {
         PIC_AddEvent(RunCfgTool, 100);
     } else
 #endif
-    RunCfgTool(NULL);
+    RunCfgTool(0);
 }
 
 void GUI_Run(bool pressed) {
@@ -3458,5 +3458,5 @@ void GUI_Run(bool pressed) {
         PIC_AddEvent(RunCfgTool, 100);
     } else
 #endif
-    RunCfgTool(NULL);
+    RunCfgTool(0);
 }
