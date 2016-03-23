--- src/fileformat/rgbeio.cpp.orig	2007-12-06 11:00:49 UTC
+++ src/fileformat/rgbeio.cpp
@@ -141,7 +141,7 @@ void rgb2rgbe( float r, float g, float b
 // Reading RGBE files
 void readRadianceHeader( FILE *file, int &width, int &height, float &exposure )
 {
-  DEBUG_STR << "RGBE: reading header..." << endl;
+  DEBUG_STR << "RGBE: reading header..." << std::endl;
 
   // read header information
   char head[255];
@@ -208,7 +208,7 @@ void readRadianceHeader( FILE *file, int
 	height = height - width;
 	}
 */
-  DEBUG_STR << "RGBE: image size " << width << "x" << height << endl;
+  DEBUG_STR << "RGBE: image size " << width << "x" << height << std::endl;
 }
 
 
@@ -389,7 +389,7 @@ void writeRadiance( FILE *file, pfs::Arr
   int width = X->getCols();
   int height = X->getRows();
 
-  DEBUG_STR << "RGBE: writing image " << width << "x" << height << endl;
+  DEBUG_STR << "RGBE: writing image " << width << "x" << height << std::endl;
 
   if( Y->getCols() != width || Y->getRows() != height ||
       Z->getCols() != width || Z->getRows() != height )
