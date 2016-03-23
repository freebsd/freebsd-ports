--- plugins/artwork/artwork_internal.h.orig	2015-07-15 07:06:25 UTC
+++ plugins/artwork/artwork_internal.h
@@ -24,6 +24,7 @@
 #ifndef __ARTWORK_INTERNAL_H
 #define __ARTWORK_INTERNAL_H
 
+#include <limits.h>
 #include "../../deadbeef.h"
 
 #define min(x,y) ((x)<(y)?(x):(y))
