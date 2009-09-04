--- ImageLib/src/gif/gif.c.orig	2009-08-07 15:16:48.000000000 -0400
+++ ImageLib/src/gif/gif.c	2009-08-07 15:19:01.000000000 -0400
@@ -4,7 +4,7 @@
 /*            Use an ultra fast compression method */
 /***************************************************/
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <memory.h>
 #include "gif.h"
 
