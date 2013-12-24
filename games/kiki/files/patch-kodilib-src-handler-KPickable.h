--- kodilib/src/handler/KPickable.h.orig	2003-04-09 06:56:01.000000000 +0400
+++ kodilib/src/handler/KPickable.h	2013-12-18 23:15:04.454779490 +0400
@@ -7,6 +7,7 @@
 #define __KPickable
 
 #include "KIntrospection.h"
+#include <sys/limits.h>
 #include <vector>
 
 #define DEBUG_PICKING		false
