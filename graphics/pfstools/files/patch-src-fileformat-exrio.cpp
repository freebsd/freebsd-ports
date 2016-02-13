--- src/fileformat/exrio.cpp.orig	2005-06-15 13:36:54 UTC
+++ src/fileformat/exrio.cpp
@@ -54,14 +54,14 @@ OpenEXRReader::OpenEXRReader( const char
   }
 
   DEBUG_STR << "OpenEXR file \"" << filename << "\" ("
-	    << width << "x" << height << ")" << endl;
+	    << width << "x" << height << ")" << std::endl;
 }
 
 void OpenEXRReader::readImage( pfs::Array2D *R, pfs::Array2D *G,
 			       pfs::Array2D *B )
 {
   assert(file!=NULL);
-  DEBUG_STR << "Reading OpenEXR file... " << endl;
+  DEBUG_STR << "Reading OpenEXR file... " << std::endl;
   
   Imf::Rgba* tmp_img = new Imf::Rgba[width*height];
 
@@ -93,7 +93,7 @@ void OpenEXRReader::readImage( pfs::Arra
 OpenEXRReader::~OpenEXRReader()
 {
   delete file;
-  file==NULL;
+  file=NULL;
 }
 
 OpenEXRWriter::OpenEXRWriter(const char* filename)
