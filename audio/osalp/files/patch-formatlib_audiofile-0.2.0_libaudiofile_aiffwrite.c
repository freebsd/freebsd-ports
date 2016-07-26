--- formatlib/audiofile-0.2.0/libaudiofile/aiffwrite.c.orig	2001-02-20 19:37:23 UTC
+++ formatlib/audiofile-0.2.0/libaudiofile/aiffwrite.c
@@ -28,6 +28,7 @@
 
 #include <assert.h>
 #include <sys/types.h>
+#include <string.h>
 #include <stdlib.h>
 
 #include "extended.h"
