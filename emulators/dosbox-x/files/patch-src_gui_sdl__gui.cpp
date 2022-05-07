--- src/gui/sdl_gui.cpp.orig	2022-05-01 06:25:42 UTC
+++ src/gui/sdl_gui.cpp
@@ -3059,7 +3059,7 @@ class ConfigurationWindow : public GUI::ToplevelWindow
             std::string url = "https://dosbox-x.com/";
 #if defined(WIN32)
             ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
-#elif defined(LINUX)
+#elif defined(LINUX) || defined(__FreeBSD__)
             system(("xdg-open "+url).c_str());
 #elif defined(MACOSX)
             system(("open "+url).c_str());
@@ -3475,7 +3475,11 @@ void GUI_Shortcut(int select) {
         PIC_AddEvent(RunCfgTool, 100);
     } else
 #endif
+#ifdef __FreeBSD__
+    RunCfgTool(0);
+#else
     RunCfgTool(NULL);
+#endif
 }
 
 void GUI_Run(bool pressed) {
@@ -3490,5 +3494,9 @@ void GUI_Run(bool pressed) {
         PIC_AddEvent(RunCfgTool, 100);
     } else
 #endif
+#ifdef __FreeBSD__
+    RunCfgTool(0);
+#else
     RunCfgTool(NULL);
+#endif
 }
