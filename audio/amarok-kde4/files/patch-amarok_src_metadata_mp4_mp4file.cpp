
$FreeBSD$

--- amarok/src/metadata/mp4/mp4file.cpp.orig
+++ amarok/src/metadata/mp4/mp4file.cpp
@@ -23,9 +23,8 @@
 
 #include "mp4tag.h"
 #include <tfile.h>
-#include <audioproperties.h>
 
-#include <stdint.h>
+#include <inttypes.h>
 
 #define MP4V2_HAS_WRITE_BUG 1
 
