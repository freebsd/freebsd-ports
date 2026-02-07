--- common/biginit.c.orig	2017-02-04 17:11:46 UTC
+++ common/biginit.c
@@ -9,7 +9,7 @@ is in the allocations of memory for the big numbers.
 #include <string.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
