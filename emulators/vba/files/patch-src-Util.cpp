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
@@ -984,7 +984,7 @@ void utilWriteData(gzFile gzFile, variab
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (*)(void *,void * const, unsigned int))gzwrite;
+  utilGzWriteFunc = (int (*)(gzFile, voidp const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
 
