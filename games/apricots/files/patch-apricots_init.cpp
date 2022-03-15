--- apricots/init.cpp.orig	2021-02-12 23:45:58 UTC
+++ apricots/init.cpp
@@ -219,7 +219,7 @@ void init_gameconstants(gamedata &g) {
 
 string getConfig(string config, string name, string defval) {
   // Pull out just the name line
-  unsigned int ndx = config.find(name);
+  size_t ndx = config.find(name);
 
   if (ndx == string::npos) {
     return defval;
@@ -240,7 +240,7 @@ string getConfig(string config, string name, string de
 
 int getConfig(string config, string name, int defval, int min, int max) {
   // Pull out just the name line
-  unsigned int ndx = config.find(name);
+  size_t ndx = config.find(name);
 
   if (ndx == string::npos) {
     return defval;
