--- src/filter.c.orig	2022-03-01 18:15:52 UTC
+++ src/filter.c
@@ -20,6 +20,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __powerpc__
+#include <altivec.h>
+#endif
+
 #include <samplerate.h>
 
 #include "types.h"
