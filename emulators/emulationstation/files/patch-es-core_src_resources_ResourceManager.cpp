--- es-core/src/resources/ResourceManager.cpp.orig	2020-11-29 16:33:50 UTC
+++ es-core/src/resources/ResourceManager.cpp
@@ -3,6 +3,10 @@
 #include "utils/FileSystemUtil.h"
 #include <fstream>
 
+#ifndef APPDATANAME
+#define APPDATANAME "EmulationStation"
+#endif
+ 
 auto array_deleter = [](unsigned char* p) { delete[] p; };
 auto nop_deleter = [](unsigned char* /*p*/) { };
 
@@ -26,6 +30,19 @@ std::string ResourceManager::getResourcePath(const std
 	if((path[0] == ':') && (path[1] == '/'))
 	{
 		std::string test;
+
+		// check in standard AppData locations
+		test = Utils::FileSystem::getHomePath() + "/.local/share/" + APPDATANAME + "/resources/" + &path[2];
+		if (Utils::FileSystem::exists(test))
+			return test;
+
+		test = std::string("/usr/local/share/") + APPDATANAME + "/resources/" + &path[2];
+		if (Utils::FileSystem::exists(test))
+			return test;
+
+		test = std::string("/usr/share/") + APPDATANAME + "/resources/" + &path[2];
+		if (Utils::FileSystem::exists(test))
+			return test;
 
 		// check in homepath
 		test = Utils::FileSystem::getHomePath() + "/.emulationstation/resources/" + &path[2];
