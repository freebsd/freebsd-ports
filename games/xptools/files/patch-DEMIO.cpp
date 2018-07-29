--- src/XESCore/DEMIO.cpp.orig	2018-07-04 19:58:36 UTC
+++ src/XESCore/DEMIO.cpp
@@ -1715,7 +1715,7 @@ bool	WriteNormalWithHeight(const string&
 	}
 
 	printf("Saving: %s\n", out_file.c_str());
-	if(WriteBitmapToPNG(&image, out_file.c_str(), NULL, NULL, 2.2f))
+	if(WriteBitmapToPNG(&image, out_file.c_str(), NULL, 0, 2.2f))
 	{
 		DestroyBitmap(&image);
 		return false;
