--- opennurbs_system.h.orig	2012-10-24 23:45:37.000000000 +0200
+++ opennurbs_system.h	2012-10-24 23:45:37.000000000 +0200
@@ -219,11 +219,6 @@
 
 #include <stdlib.h>
 #include <memory.h>
-#if defined(ON_COMPILER_XCODE)
-#include <malloc/malloc.h>
-#else
-#include <malloc.h>
-#endif
 #include <string.h>
 #include <math.h>
 #include <stdio.h>
