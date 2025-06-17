--- components/myguiplatform/myguiloglistener.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/myguiloglistener.hpp
@@ -28,7 +28,7 @@ namespace osgMyGUI
         void close() override;
         void flush() override;
 
-        void log(const std::string& _section, MyGUI::LogLevel _level, const struct tm* _time, const std::string& _message, const char* _file, int _line) override;
+        void log(std::string_view _section, MyGUI::LogLevel _level, const struct tm* _time, std::string_view _message, std::string_view _file, int _line) override;
 
         const std::string& getFileName() const { return mFileName; }
 
