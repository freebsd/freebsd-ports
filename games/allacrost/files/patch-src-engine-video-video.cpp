--- src/engine/video/video.cpp.orig	Wed Oct  4 02:42:52 2006
+++ src/engine/video/video.cpp	Wed Oct  4 03:19:03 2006
@@ -247,8 +247,6 @@
 
 	// make a temp directory and make sure it doesn't contain any files
 	// (in case the game crashed during a previous run, leaving stuff behind)
-	MakeDirectory("temp");		
-	CleanDirectory("temp");
 
 	// enable text shadows
 	EnableTextShadow(true);
@@ -438,8 +436,6 @@
 		delete iImage->second;
 		++iImage;
 	}
-	
-	RemoveDirectory("temp");	
 }
 
 
@@ -1393,7 +1389,7 @@
 string GameVideo::_CreateTempFilename(const string &extension)
 {
 	// figure out the temp filename to return
-	string filename = "temp/TEMP_";
+	string filename = "/tmp/allacrost_TEMP_";
 	filename += _nextTempFile;
 	filename += extension;
 	
