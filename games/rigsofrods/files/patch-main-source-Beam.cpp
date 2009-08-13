--- main/source/Beam.cpp.orig	2009-06-28 04:39:08.000000000 +0400
+++ main/source/Beam.cpp	2009-08-13 06:02:41.000000000 +0400
@@ -425,11 +425,8 @@
 
 	// skidmark stuff
 	useSkidmarks = (SETTINGS.getSetting("Skidmarks") == "Yes");
-	if (useSkidmarks)
-	{
-		for(int i=0; i<MAX_WHEELS*2; i++)
-			skidtrails[i] = 0;
-	}
+	for(int i=0; i<MAX_WHEELS*2; i++)
+		skidtrails[i] = 0;
 
 	collisions=icollisions;
 
