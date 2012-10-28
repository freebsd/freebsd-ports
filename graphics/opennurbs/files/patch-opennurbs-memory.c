--- opennurbs_memory.c.orig	2012-10-25 18:07:39.000000000 +0200
+++ opennurbs_memory.c	2012-10-25 18:08:08.000000000 +0200
@@ -14,6 +14,8 @@
 ////////////////////////////////////////////////////////////////
 */
 
+#include <malloc_np.h>
+
 #include "opennurbs_system.h"
 #include "opennurbs_defines.h"
 #include "opennurbs_memory.h"
@@ -113,8 +115,7 @@
     // platform, then report it to the support
     // contact on http://opennurbs.org and
     // the code will be added in the next release.
-    ON_ERROR("onmsize not implemented on this compiler or platform.")
-    sz = 0;
+    sz = malloc_usable_size( (void*)memblock );
 #endif
   }
 
