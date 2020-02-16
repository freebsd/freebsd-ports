--- backend/ricoh2_buffer.c.orig	2020-02-02 11:58:09 UTC
+++ backend/ricoh2_buffer.c
@@ -50,7 +50,7 @@
 #if defined(__APPLE__) && defined(__MACH__)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "../include/sane/sanei_debug.h"
