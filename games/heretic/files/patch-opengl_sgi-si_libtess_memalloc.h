--- opengl/sgi-si/libtess/memalloc.h.orig	2000-01-26 10:30:44 UTC
+++ opengl/sgi-si/libtess/memalloc.h
@@ -42,7 +42,7 @@
 #ifndef __memalloc_simple_h_
 #define __memalloc_simple_h_
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #define memRealloc	realloc
 #define memFree		free
