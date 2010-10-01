--- ./common/frasetup.c.orig	2004-11-23 08:13:37.000000000 -0500
+++ ./common/frasetup.c	2010-01-27 13:52:46.000000000 -0500
@@ -2,7 +2,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
   /* see Fractint.c for a description of the "include"  hierarchy */
