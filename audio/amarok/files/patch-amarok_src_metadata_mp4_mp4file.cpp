--- amarok/src/metadata/mp4/mp4file.cpp.orig	Mon Dec 17 16:53:19 2007
+++ amarok/src/metadata/mp4/mp4file.cpp	Thu Jan 31 23:14:42 2008
@@ -27,9 +27,8 @@
 
 #include "mp4tag.h"
 #include <tfile.h>
-#include <audioproperties.h>
 
-#include <stdint.h>
+#include <inttypes.h>
 
 #define MP4V2_HAS_WRITE_BUG 1
 
@@ -157,6 +156,7 @@
 #endif
 
     MP4Close(handle);
+    handle=NULL;
 
     mp4file = MP4Read(name());
     if(mp4file == MP4_INVALID_FILE_HANDLE)
