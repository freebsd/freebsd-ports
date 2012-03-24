--- common/frasetup.c.orig	2011-05-07 15:32:06.000000000 -0500
+++ common/frasetup.c	2012-03-10 16:35:22.000000000 -0500
@@ -4,7 +4,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
