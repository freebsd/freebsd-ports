--- utility/src/utility/align-ssw.H.orig	2021-12-17 22:12:23 UTC
+++ utility/src/utility/align-ssw.H
@@ -33,7 +33,8 @@
 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
-#include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde.h.h>
 
 
 #define MAPSTR "MIDNSHP=X"
