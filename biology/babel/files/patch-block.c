--- block.c.orig	Tue Jan 21 16:52:32 1997
+++ block.c	Sun Feb  1 22:56:41 2004
@@ -7,6 +7,7 @@
 */
 
 #include "bbltyp.h"
+#include <stdarg.h>
 
 /* the routine that does all the work */
 static int block__doalloc(int, block_ptr *, const char *, va_list);
@@ -99,7 +100,7 @@ block__doalloc(int clear, block_ptr *han
    void *array;
 
 /* calc how much space we are gonna need */
-   ap = initap;
+   va_copy(ap, initap);
    size = 0;
    for(i=0; types[i] != '\0'; i++)
    {
@@ -116,7 +117,7 @@ block__doalloc(int clear, block_ptr *han
 /* set up the ptrs if we can alloc the memory */
    if(*handle != NULL)
    {
-      ap = initap;
+      va_copy(ap, initap); 
       ptr = 0;
       for(i=0; types[i] != '\0'; i++)
       {
