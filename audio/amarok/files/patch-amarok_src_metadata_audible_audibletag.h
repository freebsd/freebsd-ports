
$FreeBSD$

--- amarok/src/metadata/audible/audibletag.h.orig
+++ amarok/src/metadata/audible/audibletag.h
@@ -9,6 +9,8 @@
 
 #include <config.h>
 
+#include <stdio.h>
+#include <sys/types.h>
 #include <taglib/tag.h>
 #include "taglib_audiblefile.h"
 
