--- Source/Config.cpp.orig	2007-11-22 01:14:16.000000000 +0300
+++ Source/Config.cpp	2008-01-28 00:13:47.000000000 +0300
@@ -44,8 +44,10 @@
   customlevels = 0;
   musictoggle = 1;
   azertykeyboard = 0;
-  
-  const char *cfgFile = "config.txt";
+
+  char cfgFile[PATH_MAX];
+  strcpy(cfgFile, getenv("HOME"));
+  strcat(cfgFile, "/.blackshades.config");
 
   if(!ConfigExist(cfgFile)) {
     WriteConfig(cfgFile);
