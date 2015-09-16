--- apricots/init.cpp.orig	2015-08-19 14:00:09 UTC
+++ apricots/init.cpp
@@ -218,7 +218,7 @@ void init_gameconstants(gamedata &g){
 string getConfig(string config, string name, string defval)
 {
   // Pull out just the name line
-  unsigned int ndx = config.find(name);
+  size_t ndx = config.find(name);
   
   if (ndx == string::npos)
   {
@@ -241,7 +241,7 @@ string getConfig(string config, string n
 int getConfig(string config, string name, int defval, int min, int max)
 {
   // Pull out just the name line
-  unsigned int ndx = config.find(name);
+  size_t ndx = config.find(name);
   
   if (ndx == string::npos)
   {
@@ -275,7 +275,7 @@ int getConfig(string config, string name
 void init_gamedata(gamedata &g){
 
   //--JAM: Read from config file
-  string filename(AP_PATH);
+  string filename;
   filename += "apricots.cfg";
   ifstream config_stream(filename.c_str());
   string config;
