--- tools/unitsync/unitsync.cpp.orig	2010-01-31 20:03:33.000000000 +0300
+++ tools/unitsync/unitsync.cpp	2010-02-04 16:13:38.000000000 +0300
@@ -259,8 +259,11 @@
 EXPORT(int) Init(bool isServer, int id)
 {
 	try {
-		if (!logOutputInitialised)
-			logOutput.SetFileName("unitsync.log");
+		if (!logOutputInitialised) {
+			string fname = getenv("HOME");
+			fname += "/.spring/unitsync.log";
+			logOutput.SetFileName(fname.c_str());
+		}
 		if (!configHandler)
 			ConfigHandler::Instantiate(); // use the default config file
 		FileSystemHandler::Initialize(false);
