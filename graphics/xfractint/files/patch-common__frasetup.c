--- common/frasetup.c.orig	2014-05-03 13:12:35 UTC
+++ common/frasetup.c
@@ -4,7 +4,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
