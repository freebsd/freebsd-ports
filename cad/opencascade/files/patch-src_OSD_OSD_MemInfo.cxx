--- src/OSD/OSD_MemInfo.cxx.orig	2014-04-29 11:40:36.000000000 +0200
+++ src/OSD/OSD_MemInfo.cxx	2014-05-04 14:18:16.000000000 +0200
@@ -28,7 +28,7 @@
   #include <malloc/malloc.h>
 #else
   #include <unistd.h>
-  #include <malloc.h>
+  #include <stdlib.h>
 #endif
 
 #include <string>
