--- BlockOut/GLApp/GLSprite.cpp.orig	2014-05-06 16:47:55.000000000 +0700
+++ BlockOut/GLApp/GLSprite.cpp	2015-08-17 10:37:35.000000000 +0600
@@ -2,7 +2,7 @@
 // 2D sprites
 // -----------------------------------------------
 #include "GLSprite.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #undef LoadImage
