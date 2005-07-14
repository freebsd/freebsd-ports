--- src/helper/str.c.orig	Thu Jul 14 10:37:13 2005
+++ src/helper/str.c	Thu Jul 14 17:52:39 2005
@@ -12,6 +12,7 @@
 #include "helper.h"
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
 
 char* strn_dup (const char* input, size_t insize) {
   void* retval;
