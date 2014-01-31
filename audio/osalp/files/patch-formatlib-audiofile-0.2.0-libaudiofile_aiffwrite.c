--- formatlib/audiofile-0.2.0/libaudiofile/aiffwrite.c.orig	2014-01-30 15:01:36.000000000 +0100
+++ formatlib/audiofile-0.2.0/libaudiofile/aiffwrite.c	2014-01-30 15:01:51.000000000 +0100
@@ -28,6 +28,7 @@
 
 #include <assert.h>
 #include <sys/types.h>
+#include <string.h>
 #include <stdlib.h>
 
 #include "extended.h"
