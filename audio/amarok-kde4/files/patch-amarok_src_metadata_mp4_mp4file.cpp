
$FreeBSD$

--- amarok/src/metadata/mp4/mp4file.cpp.orig
+++ amarok/src/metadata/mp4/mp4file.cpp
@@ -27,9 +27,8 @@
 
 #include "mp4tag.h"
 #include <tfile.h>
-#include <audioproperties.h>
 
-#include <stdint.h>
+#include <inttypes.h>
 
 #define MP4V2_HAS_WRITE_BUG 1
 
@@ -156,10 +155,8 @@
     }
 #endif
 
-    if(!MP4Close(handle))
-    {
-        fprintf(stderr, "close failed\n");
-    }
+    MP4Close(handle);
+    handle=NULL;
 
     mp4file = MP4Read(name());
     if(mp4file == MP4_INVALID_FILE_HANDLE)
