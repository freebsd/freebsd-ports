--- db.cc.orig	Wed Sep  1 23:42:10 2004
+++ db.cc	Wed Sep  1 23:42:58 2004
@@ -36,7 +36,7 @@
 #ifdef __APPLE__
 	#include <malloc/malloc.h>
 #else
-	#include <malloc.h>
+	#include <stdlib.h>
 #endif
 
 #ifdef MPEG4_ENABLE
