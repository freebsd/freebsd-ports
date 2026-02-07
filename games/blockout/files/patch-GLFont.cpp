--- BlockOut/GLApp/GLFont.cpp.orig	2014-05-06 16:47:55.000000000 +0700
+++ BlockOut/GLApp/GLFont.cpp	2015-08-17 10:31:54.000000000 +0600
@@ -2,7 +2,7 @@
 // Simple 2D font
 // -----------------------------------------------
 #include "GLFont.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #undef LoadImage
