--- acelib/memsubs.c.orig	Mon Jan 11 02:01:29 1999
+++ acelib/memsubs.c	Thu Jul 27 17:18:45 2000
@@ -21,7 +21,7 @@
 #if defined(NEXT) || defined(HP) || defined(MACINTOSH) 
 extern void* malloc(mysize_t size) ;
 #elif !defined(WIN32) && !defined(DARWIN)
-#include <malloc.h>   /* normal machines  */
+#include <stdlib.h>   /* normal machines  */
 #endif
 
 /********** primary type definition **************/
