--- pro_alloc.c.orig	Wed Jul  4 01:37:21 2007
+++ pro_alloc.c	Wed Nov  7 12:35:05 2007
@@ -40,11 +40,12 @@
 #include "pro_incl.h"
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
+#else
+#include <malloc.h>
 #endif /* HAVE_STDLIB_H */
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif /* HAVE_STRING_H */
-#include <malloc.h>
 
 /*
  When each block is allocated, there is a two-word structure
