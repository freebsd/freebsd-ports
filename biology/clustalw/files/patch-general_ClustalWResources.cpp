--- general/ClustalWResources.cpp.orig	Thu Jul 19 18:44:22 2007
+++ general/ClustalWResources.cpp	Wed Oct 31 17:39:01 2007
@@ -33,7 +33,7 @@
     executablePath = ".";
     
     //installPath
-    installPath = ".";
+    installPath = DATADIR;
     char *env;
     if ((env = getenv(CLUW_INSTALL_DIR)) != 0) 
     {
