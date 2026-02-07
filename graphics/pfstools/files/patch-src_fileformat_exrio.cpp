--- src/fileformat/exrio.cpp.orig	2018-01-19 06:59:44 UTC
+++ src/fileformat/exrio.cpp
@@ -93,7 +93,7 @@ void OpenEXRReader::readImage( pfs::Arra
 OpenEXRReader::~OpenEXRReader()
 {
   delete file;
-  file==NULL;
+  file=NULL;
 }
 
 OpenEXRWriter::OpenEXRWriter(const char* filename)
