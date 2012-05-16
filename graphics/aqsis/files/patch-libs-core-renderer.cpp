--- libs/core/renderer.cpp.orig	2012-02-20 18:46:39.000000000 +0300
+++ libs/core/renderer.cpp	2012-02-20 18:46:49.000000000 +0300
@@ -1195,7 +1195,7 @@
 	if(shaderFile)
 	{
 		Aqsis::log() << info << "Loading shader \"" << strName
-			<< "\" from file \"" << shaderPath.file_string()
+			<< "\" from file \"" << shaderPath.string()
 			<< "\"" << std::endl;
 
 		std::string dsoPath;
