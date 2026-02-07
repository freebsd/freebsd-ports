--- common/memory.c.orig	2014-05-03 13:12:35 UTC
+++ common/memory.c
@@ -2,7 +2,7 @@
 #include <limits.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
