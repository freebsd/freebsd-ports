--- VBA/Util.cpp.orig	2016-11-24 13:15:44 UTC
+++ VBA/Util.cpp
@@ -917,7 +917,7 @@ bool utilIsGSF(const char * file)
   
 
   if(strlen(file) > 4) {
-    char *p = strrchr(file,'.');
+    const char *p = strrchr(file,'.');
 
 	if(p != NULL) {
 	  if(_stricmp(p, ".gsf") == 0)
@@ -934,7 +934,7 @@ bool utilIsGBAImage(const char * file)
 {
   cpuIsMultiBoot = false;
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       //if(_stricmp(p, ".gba") == 0)
@@ -1484,7 +1484,8 @@ void utilWriteData(gzFile gzFile, variab
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite;
+  // utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite; 
+  utilGzWriteFunc = (int (ZEXPORT *)(gzFile_s*, void * const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
 
