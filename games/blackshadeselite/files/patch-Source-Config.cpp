--- Source/Config.cpp.orig	2007-11-22 01:14:16.000000000 +0300
+++ Source/Config.cpp	2015-03-27 01:33:20.608154000 +0300
@@ -19,6 +19,10 @@
  */
 #include <fstream>
 #include <iostream>
+#include <cstdlib>
+#include <cstring>
+
+#include <limits.h>
 
 #include "Config.h"
 
@@ -44,8 +48,10 @@
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
