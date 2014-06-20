--- src/fileformat/exrio.cpp.orig	2005-06-15 13:36:54.000000000 +0000
+++ src/fileformat/exrio.cpp	2014-02-20 19:04:01.546588828 +0000
@@ -54,14 +54,14 @@
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
 
@@ -93,7 +93,7 @@
 OpenEXRReader::~OpenEXRReader()
 {
   delete file;
-  file==NULL;
+  file=NULL;
 }
 
 OpenEXRWriter::OpenEXRWriter(const char* filename)
