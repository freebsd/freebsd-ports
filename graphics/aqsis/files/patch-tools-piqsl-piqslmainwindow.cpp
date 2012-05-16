--- tools/piqsl/piqslmainwindow.cpp.orig	2012-02-20 18:43:33.000000000 +0300
+++ tools/piqsl/piqslmainwindow.cpp	2012-02-20 18:44:04.000000000 +0300
@@ -186,7 +186,7 @@
 	char* filename = fl_file_chooser("Load Image", "All Supported Files (*.{tif,tiff,exr,env,tx,tex,shad,zfile,sm})\tTIFF Files (*.{tif,tiff})\tOpenEXR Files (*.exr)\tTeqser Files (*.{env,tx,tex})\tShadow Files (*.{shad,zfile,sm})", "");
 	if(filename)
 	{
-		std::string name = boost::filesystem::path(filename).leaf();
+                std::string name = boost::filesystem::path(filename).leaf().string();
 		loadImageToCurrentBook(name, filename);
 		updateImageList();
 	}
