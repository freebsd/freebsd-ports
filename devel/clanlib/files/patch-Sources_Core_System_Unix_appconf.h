--- Sources/Core/System/Unix/appconf.h.orig	Wed May  3 20:29:00 2000
+++ Sources/Core/System/Unix/appconf.h	Mon Aug  2 10:19:18 2004
@@ -527,7 +527,9 @@
 
 //protected: --- if FileConfig::ConfigEntry is not public, functions in
 //               ConfigGroup such as Find/AddEntry can't return ConfigEntry*!
+protected:
   class ConfigGroup;
+public:
   class ConfigEntry
   {
   private:
