--- app/compressedgif.cpp.orig	Sat May 22 16:02:26 2004
+++ app/compressedgif.cpp	Sun Nov 28 21:37:00 2004
@@ -9,6 +9,10 @@
 #include <api.h>
 #include <assert.h>
 
+#include "blob_private.h"
+#include "image_private.h"
+#include "exception_private.h"
+
 #ifndef False
 #define False 0
 #endif
