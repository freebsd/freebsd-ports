--- block.c.orig	Tue Jan 21 16:52:32 1997
+++ block.c	Sun Feb  1 22:56:41 2004
@@ -7,6 +7,10 @@
 */
 
 #include "bbltyp.h"
+#include <osreldate.h>
+#if __FreeBSD_version > 500000
+#include <stdarg.h>
+#endif
 
 /* the routine that does all the work */
 static int block__doalloc(int, block_ptr *, const char *, va_list);
@@ -99,7 +103,11 @@
    void *array;
 
 /* calc how much space we are gonna need */
+   #if __FreeBSD_version > 500000 && defined(__amd64__)
+   va_copy(ap, initap);
+   #else
    ap = initap;
+   #endif
    size = 0;
    for(i=0; types[i] != '\0'; i++)
    {
@@ -115,8 +123,12 @@
 
 /* set up the ptrs if we can alloc the memory */
    if(*handle != NULL)
-   {
+   {  
+      #if __FreeBSD_version > 500000 && defined(__amd64__)
+      va_copy(ap, initap); 
+      #else
       ap = initap;
+      #endif
       ptr = 0;
       for(i=0; types[i] != '\0'; i++)
       {
