--- src/dbconnect/dbconnect.cpp.orig	Mon Aug  9 15:54:42 2004
+++ src/dbconnect/dbconnect.cpp	Mon Aug  9 15:56:41 2004
@@ -117,7 +117,7 @@
 //------------------------------------------------------------------------------
 DbConnection::DbConnection(
          Driver driver, 
-         const string &configFile)
+         const string &cfgFile)
 :
    ptr_getAuthor(NULL),
    ptr_getVendor(NULL),
@@ -147,10 +147,10 @@
 
 
    // 1. Use the file iif given in configFile param.
-   if (configFile.length() > 0)
+   if (cfgFile.length() > 0)
    {
       // Try and read the information from the config file.
-      ConfigFile configFile(configFile.c_str());
+      ConfigFile configFile(cfgFile.c_str());
       configFile.read();
 
       if (configFile.hasKeyName("dbconnect", "driverPath"))
