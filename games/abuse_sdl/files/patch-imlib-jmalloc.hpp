--- src/imlib/jmalloc.hpp.old	2009-11-04 20:07:54.000000000 -0600
+++ src/imlib/jmalloc.hpp	2009-11-04 20:08:16.000000000 -0600
@@ -12,6 +12,7 @@
 
 
 #include <stdlib.h>
+#include <stdint.h>
 
 #ifdef MANAGE_MEM
 enum {ALLOC_SPACE_STATIC,ALLOC_SPACE_CACHE};
