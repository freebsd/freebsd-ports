--- opennurbs_system.h.orig	2017-02-11 10:13:51 UTC
+++ opennurbs_system.h
@@ -219,11 +219,7 @@
 
 #include <stdlib.h>
 #include <memory.h>
-#if defined(ON_COMPILER_XCODE)
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
+#include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <stdio.h>
