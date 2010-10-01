--- ./common/fractals.c.orig	2008-09-17 21:52:35.000000000 -0400
+++ ./common/fractals.c	2010-01-27 13:52:46.000000000 -0500
@@ -41,7 +41,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
