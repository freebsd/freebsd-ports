
$FreeBSD$

--- amarok/src/metadata/audible/audibleproperties.h.orig
+++ amarok/src/metadata/audible/audibleproperties.h
@@ -9,6 +9,8 @@
 
 #include <config.h>
 
+#include <stdio.h>
+#include <sys/types.h>
 #include <taglib/audioproperties.h>
 #include <taglib/tstring.h>
 
