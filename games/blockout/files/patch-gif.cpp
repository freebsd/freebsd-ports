--- ImageLib/src/gif/gif.cpp.orig	2015-08-20 21:29:33.000000000 +0600
+++ ImageLib/src/gif/gif.cpp	2015-08-20 21:29:46.000000000 +0600
@@ -4,7 +4,7 @@
 /*            Use an ultra fast compression method */
 /***************************************************/
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <memory.h>
 #include <string.h>
 #include "gif.h"
