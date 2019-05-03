--- src/openrct2/config/Config.cpp.orig	2018-08-26 20:20:13 UTC
+++ src/openrct2/config/Config.cpp
@@ -650,6 +650,9 @@ namespace Config
      */
     static std::string FindRCT2Path()
     {
+
+	return "%%DATADIR%%";
+
         log_verbose("config_find_rct2_path(...)");
 
         static constexpr const utf8* searchLocations[] = {
