--- fractals.c.orig	Tue Sep  7 00:38:10 1999
+++ fractals.c	Sun Dec  7 10:42:38 2003
@@ -41,7 +41,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
