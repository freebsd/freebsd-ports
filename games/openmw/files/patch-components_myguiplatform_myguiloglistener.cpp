--- components/myguiplatform/myguiloglistener.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/myguiloglistener.cpp
@@ -25,7 +25,7 @@ namespace osgMyGUI
             mStream.flush();
     }
 
-    void CustomLogListener::log(const std::string& _section, MyGUI::LogLevel _level, const struct tm* _time, const std::string& _message, const char* _file, int _line)
+    void CustomLogListener::log(std::string_view _section, MyGUI::LogLevel _level, const struct tm* _time, std::string_view _message, std::string_view _file, int _line)
     {
         if (mStream.is_open())
         {
