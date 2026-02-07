--- Trigger/main.cpp.orig	2019-03-26 21:41:24 UTC
+++ Trigger/main.cpp
@@ -471,7 +471,7 @@ void MainApp::loadConfig()
   if (!PHYSFS_exists(cfgfilename.c_str())) {
 #ifdef UNIX
     const std::vector<std::string> cfghidingplaces {
-        "/usr/share/games/trigger-rally/"
+        "%%PREFIX%%/share/games/trigger-rally/"
     };
 
     for (const std::string &cfgpath: cfghidingplaces)
