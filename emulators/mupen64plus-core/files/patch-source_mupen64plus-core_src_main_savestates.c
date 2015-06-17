--- source/mupen64plus-core/src/main/savestates.c	2015-06-12 17:56:37.000000000 -0500
+++ source/mupen64plus-core/src/main/savestates.c	2015-06-12 17:56:55.000000000 -0500
@@ -57,8 +57,8 @@
 #include "workqueue.h"
 
 #ifdef LIBMINIZIP
-    #include <unzip.h>
-    #include <zip.h>
+    #include <minizip/unzip.h>
+    #include <minizip/zip.h>
 #else
     #include "main/zip/unzip.h"
     #include "main/zip/zip.h"
