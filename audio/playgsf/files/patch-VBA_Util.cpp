--- VBA/Util.cpp.orig	2016-07-26 15:40:39 UTC
+++ VBA/Util.cpp
@@ -1484,7 +1484,8 @@ void utilWriteData(gzFile gzFile, variab
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite;
+  // utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite; 
+  utilGzWriteFunc = (int (ZEXPORT *)(gzFile_s*, void * const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
 
