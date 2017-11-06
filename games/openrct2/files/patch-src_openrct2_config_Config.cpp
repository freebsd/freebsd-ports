--- src/openrct2/config/Config.cpp.orig	2017-08-09 22:02:59 UTC
+++ src/openrct2/config/Config.cpp
@@ -591,6 +591,8 @@ namespace Config
     {
         log_verbose("config_find_rct2_path(...)");
 
+        return "%%DATADIR%%";
+
         static const utf8 * searchLocations[] =
         {
             "C:\\GOG Games\\RollerCoaster Tycoon 2 Triple Thrill Pack",
