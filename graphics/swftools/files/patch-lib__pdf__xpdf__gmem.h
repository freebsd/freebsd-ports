--- lib/pdf/xpdf/gmem.h.orig	Wed Oct 11 02:54:28 2006
+++ lib/pdf/xpdf/gmem.h	Mon Jan 22 13:07:59 2007
@@ -19,13 +19,13 @@
  * Same as malloc, but prints error message and exits if malloc()
  * returns NULL.
  */
-extern void *gmalloc(int size);
+extern void *gmalloc(size_t size);
 
 /*
  * Same as realloc, but prints error message and exits if realloc()
  * returns NULL.  If <p> is NULL, calls malloc instead of realloc().
  */
-extern void *grealloc(void *p, int size);
+extern void *grealloc(void *p, size_t size);
 
 /*
  * These are similar to gmalloc and grealloc, but take an object count
@@ -33,8 +33,8 @@
  * bytes, but there is an additional error check that the total size
  * doesn't overflow an int.
  */
-extern void *gmallocn(int nObjs, int objSize);
-extern void *greallocn(void *p, int nObjs, int objSize);
+extern void *gmallocn(int nObjs, size_t objSize);
+extern void *greallocn(void *p, int nObjs, size_t objSize);
 
 /*
  * Same as free, but checks for and ignores NULL pointers.
