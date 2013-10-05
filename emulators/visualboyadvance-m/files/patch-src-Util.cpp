--- src/Util.cpp.orig	2013-10-05 07:22:08.455933950 -0300
+++ src/Util.cpp	2013-10-05 07:22:40.675934470 -0300
@@ -544,7 +544,7 @@
 
 gzFile utilGzOpen(const char *file, const char *mode)
 {
-  utilGzWriteFunc = (int (ZEXPORT *)(void *,void * const, unsigned int))gzwrite;
+  utilGzWriteFunc = (int (ZEXPORT *)(gzFile_s *,void * const, unsigned int))gzwrite;
   utilGzReadFunc = gzread;
   utilGzCloseFunc = gzclose;
   utilGzSeekFunc = gzseek;
