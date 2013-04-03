--- ./VBA/Util.cpp.orig	2013-04-02 11:32:02.322879639 +0200
+++ ./VBA/Util.cpp	2013-04-02 11:33:58.107884638 +0200
@@ -1484,7 +1484,8 @@
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite;
+  // utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite; 
+  utilGzWriteFunc = (int (ZEXPORT *)(gzFile_s*, void * const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
 
