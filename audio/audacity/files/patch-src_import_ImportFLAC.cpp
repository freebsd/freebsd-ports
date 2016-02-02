--- src/import/ImportFLAC.cpp.orig	2016-01-08 22:05:48 UTC
+++ src/import/ImportFLAC.cpp
@@ -296,7 +296,7 @@ ImportFileHandle *FLACImportPlugin::Open
    int cnt;
    wxFile binaryFile;
    if (!binaryFile.Open(filename)) {
-      return false; // File not found
+      return NULL; // File not found
    }
 
 #ifdef USE_LIBID3TAG
@@ -313,7 +313,7 @@ ImportFileHandle *FLACImportPlugin::Open
 
    if (cnt == wxInvalidOffset || strncmp(buf, FLAC_HEADER, 4) != 0) {
       // File is not a FLAC file
-      return false;
+      return NULL;
    }
 
    // Open the file for import
