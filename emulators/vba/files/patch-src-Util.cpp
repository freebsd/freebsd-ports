--- src/Util.cpp.orig	2004-05-20 19:42:37.000000000 +0200
+++ src/Util.cpp	2012-05-02 20:49:07.000000000 +0200
@@ -79,7 +79,7 @@ bool utilWritePNGFile(const char *fileNa
     return false;
   }
 
-  if(setjmp(png_ptr->jmpbuf)) {
+  if(setjmp(png_jmpbuf(png_ptr))) {
     png_destroy_write_struct(&png_ptr,NULL);
     fclose(fp);
     return false;
@@ -478,7 +478,7 @@ bool utilIsGBAImage(const char * file)
 {
   cpuIsMultiBoot = false;
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".gba") == 0)
@@ -502,7 +502,7 @@ bool utilIsGBAImage(const char * file)
 bool utilIsGBImage(const char * file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".gb") == 0)
@@ -522,7 +522,7 @@ bool utilIsGBImage(const char * file)
 bool utilIsZipFile(const char *file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".zip") == 0)
@@ -537,7 +537,7 @@ bool utilIsZipFile(const char *file)
 bool utilIsRarFile(const char *file)
 {
   if(strlen(file) > 4) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".rar") == 0)
@@ -552,7 +552,7 @@ bool utilIsRarFile(const char *file)
 bool utilIsGzipFile(const char *file)
 {
   if(strlen(file) > 3) {
-    char * p = strrchr(file,'.');
+    const char * p = strrchr(file,'.');
 
     if(p != NULL) {
       if(_stricmp(p, ".gz") == 0)
@@ -984,7 +984,7 @@ void utilWriteData(gzFile gzFile, variab
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (*)(void *,void * const, unsigned int))gzwrite;
+  utilGzWriteFunc = (int (*)(gzFile, voidp const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
 
