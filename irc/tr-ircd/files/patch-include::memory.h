--- include/memory.h.orig	Sun May 19 11:25:19 2002
+++ include/memory.h	Sun May 19 11:25:32 2002
@@ -17,12 +17,6 @@
  *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#ifndef HAVE_STDINT_H
-#ifndef HAVE_UINTPTR_T
-typedef unsigned long uintptr_t;
-#endif
-#endif
-
 #define MyFree(x)       if ((x) != NULL) free(x)
 
 extern char *MyMalloc(size_t);
