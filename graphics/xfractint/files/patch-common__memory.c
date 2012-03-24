--- common/memory.c.orig	2012-03-10 16:57:05.000000000 -0500
+++ common/memory.c	2012-03-10 16:57:36.000000000 -0500
@@ -2,7 +2,7 @@
 #include <limits.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
