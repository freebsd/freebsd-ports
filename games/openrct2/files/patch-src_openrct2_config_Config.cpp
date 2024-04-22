--- src/openrct2/config/Config.cpp.orig	2024-03-02 20:26:41 UTC
+++ src/openrct2/config/Config.cpp
@@ -700,6 +700,8 @@ namespace Config
     {
         LOG_VERBOSE("config_find_rct2_path(...)");
 
+        return "%%DATADIR%%";
+
         static constexpr u8string_view searchLocations[] = {
             R"(C:\Program Files\Steam\steamapps\common\Rollercoaster Tycoon 2)",
             R"(C:\Program Files (x86)\Steam\steamapps\common\Rollercoaster Tycoon 2)",
