--- samples/SampleUtilities/Data.cpp.orig	Mon Jan 26 13:46:44 2004
+++ samples/SampleUtilities/Data.cpp	Mon Jan 26 13:49:15 2004
@@ -53,7 +53,7 @@
 		sprintf(szPath, szFullPath);
 		return true;
 	}
-	sprintf(szFullPath, "/usr/local/share/DemeterSampleData-3.20/");
+	sprintf(szFullPath, "%%EXAMPLESDIR%%/DemeterSampleData-3.20/");
 	if (TestPath(szFullPath))
 	{
 		sprintf(szPath, szFullPath);
