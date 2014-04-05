--- source/blender/blenloader/intern/versioning_270.c.orig	2014-03-22 12:10:23.000000000 +0100
+++ source/blender/blenloader/intern/versioning_270.c	2014-03-22 12:10:40.000000000 +0100
@@ -28,6 +28,8 @@
 #include "BLI_utildefines.h"
 #include "BLI_compiler_attrs.h"
 
+#include <stddef.h>
+
 /* allow readfile to use deprecated functionality */
 #define DNA_DEPRECATED_ALLOW
 
