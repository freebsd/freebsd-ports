--- src/GLEXT/GLBitmap.cpp.orig	Wed Jul 30 17:41:26 2003
+++ src/GLEXT/GLBitmap.cpp	Sun Aug  3 09:07:12 2003
@@ -24,11 +24,11 @@
 //////////////////////////////////////////////////////////////////////
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 #include <GLEXT/GLState.h>
 #include <GLEXT/GLBitmap.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 
 //////////////////////////////////////////////////////////////////////
 // Construction/Destruction
