--- common/lsys.c.orig	2015-01-19 18:35:16 UTC
+++ common/lsys.c
@@ -4,7 +4,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
