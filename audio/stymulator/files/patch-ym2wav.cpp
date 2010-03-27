--- ym2wav.cpp.orig	2010-03-27 16:25:32.000000000 +0100
+++ ym2wav.cpp	2010-03-27 16:26:14.000000000 +0100
@@ -74,9 +74,9 @@
 	char *platform;
 
 	if (PLATFORM)
-		platform = "64bit";
+		platform = ((char *)"64bit");
 	else
-		platform = "32bit";
+		platform = ((char *)"32bit");
 
 	//--------------------------------------------------------------------------
 	// Checks args.
