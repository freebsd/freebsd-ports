--- common/fractals.c.orig	2011-05-08 11:47:58.000000000 -0500
+++ common/fractals.c	2012-03-10 16:33:40.000000000 -0500
@@ -43,7 +43,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
