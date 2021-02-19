--- common/fractalb.c.orig	2020-07-05 20:02:50 UTC
+++ common/fractalb.c
@@ -12,7 +12,7 @@ fractal routines.
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
