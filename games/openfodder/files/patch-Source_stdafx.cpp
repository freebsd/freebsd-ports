Check DATADIR if ~/.local/share/ exists but lacks OpenFodder subdirectory.
Allows to run demo on first launch on a common desktop.

--- Source/stdafx.cpp.orig	2018-12-15 08:47:57 UTC
+++ Source/stdafx.cpp
@@ -249,7 +249,7 @@ void local_BasePathGenerate() {
     }
 
     // Fall back just incase
-    if (!FinalPath.size())
+    if (!local_FileExists(FinalPath + "OpenFodder/"))
         FinalPath = "/usr/local/share/";
 
     filePathFinal << FinalPath << "OpenFodder/";
