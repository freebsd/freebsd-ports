--- libs/tex/maketexture/maketexture.cpp.orig	2012-02-20 18:10:38.000000000 +0300
+++ libs/tex/maketexture/maketexture.cpp	2012-02-20 18:10:56.000000000 +0300
@@ -335,8 +335,8 @@
 	{
 		inFileRealName = inFileName.string() + ".tif";
 		TqInt bakeRes = static_cast<TqInt>(paramList.find<TqFloat>("bake", 256));
-		bakeToTiff(inFileName.file_string().c_str(),
-				   inFileRealName.file_string().c_str(), bakeRes);
+		bakeToTiff(inFileName.string().c_str(),
+				   inFileRealName.string().c_str(), bakeRes);
 	}
 
 	// Open the input file
