--- backend/ricoh2_buffer.c.orig	2019-10-09 14:45:51 UTC
+++ backend/ricoh2_buffer.c
@@ -46,7 +46,7 @@
 
 #include <memory.h>
 #include <assert.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "../include/sane/sanei_debug.h"
 
