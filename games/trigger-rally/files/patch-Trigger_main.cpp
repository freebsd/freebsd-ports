--- Trigger/main.cpp.orig	2017-03-02 19:21:27 UTC
+++ Trigger/main.cpp
@@ -469,7 +469,7 @@ void MainApp::loadConfig()
   if (!PHYSFS_exists(cfgfilename.c_str())) {
 #ifdef UNIX
     const std::vector<std::string> cfghidingplaces {
-        "/usr/share/games/trigger-rally/"
+        "/usr/local/share/games/trigger-rally/"
     };
 
     for (const std::string &cfgpath: cfghidingplaces)
