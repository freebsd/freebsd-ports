--- mcs/class/Microsoft.Build.Engine/Microsoft.Build.BuildEngine/DirectoryScanner.cs.orig	2014-02-28 08:27:40.000000000 +0100
+++ mcs/class/Microsoft.Build.Engine/Microsoft.Build.BuildEngine/DirectoryScanner.cs	2014-02-28 08:28:16.000000000 +0100
@@ -98,7 +98,7 @@
 				int offset = 0;
 				string full_path;
 				if (Path.IsPathRooted (name)) {
-					full_path = name;
+					full_path = Path.GetFullPath (name);
 					baseDirectory = new DirectoryInfo (Path.GetPathRoot (name));
 					if (IsRunningOnWindows)
 						// skip the "drive:"
