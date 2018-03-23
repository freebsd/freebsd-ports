--- src/openrct2/config/Config.cpp.orig	2018-03-18 20:26:14 UTC
+++ src/openrct2/config/Config.cpp
@@ -602,6 +602,9 @@ namespace Config
      */
     static std::string FindRCT2Path()
     {
+
+	return "%%DATADIR%%";
+
         log_verbose("config_find_rct2_path(...)");
 
         static constexpr const utf8 * searchLocations[] =
