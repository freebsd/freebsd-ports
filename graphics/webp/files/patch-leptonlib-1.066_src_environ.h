--- leptonlib-1.066/src/environ.h.orig	2010-11-23 12:47:09.000000000 +0100
+++ leptonlib-1.066/src/environ.h	2010-11-23 12:45:55.000000000 +0100
@@ -205,6 +205,7 @@ enum {
  *  on all heap data except for Pix.  Memory management for Pix
  *  also defaults to malloc and free.  See pix1.c for details.
  *------------------------------------------------------------------------*/
+#include <stdlib.h>
 #define MALLOC(blocksize)           malloc(blocksize)
 #define CALLOC(numelem, elemsize)   calloc(numelem, elemsize)
 #define REALLOC(ptr, blocksize)     realloc(ptr, blocksize)
