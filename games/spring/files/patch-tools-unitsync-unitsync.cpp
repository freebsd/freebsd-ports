--- tools/unitsync/unitsync.cpp.orig	2009-09-04 21:32:13.000000000 +0400
+++ tools/unitsync/unitsync.cpp	2009-09-08 04:13:16.000000000 +0400
@@ -264,7 +264,9 @@
 	try {
 		if (!logOutputInitialised)
 		{
-			logOutput.SetFilename("unitsync.log");
+			string fname = getenv("HOME");
+			fname += "/.spring/unitsync.log";
+			logOutput.SetFilename(fname.c_str());
 			logOutput.Initialize();
 			logOutputInitialised = true;
 		}
