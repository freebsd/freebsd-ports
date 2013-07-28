--- ofc/DGZipFile.h.orig	2008-08-02 15:15:11.000000000 +0000
+++ ofc/DGZipFile.h
@@ -46,6 +46,7 @@
 #endif
 
 #ifdef HAVE_DGZIPFILE
+#include <zlib.h>
 
 // the seek origins
 #define DGZ_SEEK_SET  (0)    // Seek from the start of the file
@@ -114,7 +115,7 @@
 @interface DGZipFile : Object <DTextReadable,DTextWritable,DDataReadable,DDataWritable>
 {
 @private
-  void           *_file;    // the file pointer
+  gzFile          _file;    // the file pointer
 }
 
 #endif
