--- apricots/init.cpp.orig	2013-10-18 03:20:08.162773332 +0400
+++ apricots/init.cpp	2013-10-18 03:21:49.134378818 +0400
@@ -275,7 +275,7 @@
 void init_gamedata(gamedata &g){
 
   //--JAM: Read from config file
-  string filename(AP_PATH);
+  string filename;
   filename += "apricots.cfg";
   ifstream config_stream(filename.c_str());
   string config;
