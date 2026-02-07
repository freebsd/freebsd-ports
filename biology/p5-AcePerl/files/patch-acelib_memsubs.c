--- acelib/memsubs.c.orig	2002-11-24 19:24:23 UTC
+++ acelib/memsubs.c
@@ -21,7 +21,7 @@
 #if defined(NEXT) || defined(HP) || defined(MACINTOSH) 
 extern void* malloc(mysize_t size) ;
 #elif !defined(WIN32) && !defined(DARWIN)
-#include <malloc.h>   /* normal machines  */
+#include <stdlib.h>   /* normal machines  */
 #endif
 
 /********** primary type definition **************/
