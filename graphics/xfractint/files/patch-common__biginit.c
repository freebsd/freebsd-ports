--- common/biginit.c.orig	2011-05-07 15:28:14.000000000 -0500
+++ common/biginit.c	2012-03-10 17:13:34.000000000 -0500
@@ -9,7 +9,7 @@
 #include <string.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
