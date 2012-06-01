--- libs/auxfun/image.cpp.orig	2008-05-02 08:56:04.000000000 +0200
+++ libs/auxfun/image.cpp	2012-05-04 12:31:16.000000000 +0200
@@ -6,6 +6,7 @@
 #include "image.h"
 #include <zlib.h>
 #include <png.h>
+#include <pngpriv.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <math.h>
@@ -94,7 +95,7 @@
 
     png_init_io (png, file);
 
-    if (setjmp (png->jmpbuf))
+    if (setjmp (png_jmpbuf(png)))
         // If we get here, we had a problem reading the file
         goto nomem;
 
@@ -157,7 +158,7 @@
     row_pointers = new png_bytep [Height];
 
     if (!row_pointers
-        || setjmp (png->jmpbuf))             // Set a new exception handler
+        || setjmp (png_jmpbuf(png)))             // Set a new exception handler
     {
         delete [] row_pointers;
     nomem:
@@ -214,7 +215,7 @@
     }
 
     /* Catch processing errors */
-    if (setjmp(png->jmpbuf))
+    if (setjmp(png_jmpbuf(png)))
         /* If we get here, we had a problem writing the file */
         goto error2;
 
