--- ofc/DGZipFile.m.orig	2008-08-02 05:58:14.000000000 +0000
+++ ofc/DGZipFile.m
@@ -31,10 +31,6 @@
 #include <stdio.h>
 #include <string.h>
 
-#ifdef HAVE_DGZIPFILE
-#include <zlib.h>
-#endif
-
 #include "ofc/DDatable.h"
 
 
@@ -123,7 +119,7 @@
 @interface DGZipFile : Object <DTextReadable,DTextWritable,DDataReadable,DDataWritable>
 {
 @private
-  void           *_file;    // the file pointer
+  gzFile          _file;    // the file pointer
 }
 
 #endif
