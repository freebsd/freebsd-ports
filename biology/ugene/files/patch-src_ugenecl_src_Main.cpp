--- src/ugenecl/src/Main.cpp.orig	2026-03-01 18:44:47 UTC
+++ src/ugenecl/src/Main.cpp
@@ -151,7 +151,7 @@ static void setScriptsSearchPath() {
         scriptsSearchPath.push_back(appDirPath + RELATIVE_DEV_SCRIPTS_DIR);
     }
     if (scriptsSearchPath.empty()) {
-        scriptsSearchPath.push_back("/");
+        scriptsSearchPath.push_back("/usr/local/share/ugene/scripts");
     }
     QDir::setSearchPaths(PATH_PREFIX_SCRIPTS, scriptsSearchPath);
 }
@@ -178,7 +178,7 @@ static void setDataSearchPaths() {
     }
 
     if (dataSearchPaths.empty()) {
-        dataSearchPaths.push_back("/");
+        dataSearchPaths.push_back("/usr/local/share/ugene/data");
     }
 
     QDir::setSearchPaths(PATH_PREFIX_DATA, dataSearchPaths);
