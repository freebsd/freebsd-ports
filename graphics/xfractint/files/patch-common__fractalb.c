--- common/fractalb.c.orig	2011-05-07 15:31:02.000000000 -0500
+++ common/fractalb.c	2012-03-10 16:31:30.000000000 -0500
@@ -12,7 +12,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
