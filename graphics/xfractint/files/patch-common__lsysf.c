--- common/lsysf.c.orig	2014-05-03 13:12:35 UTC
+++ common/lsysf.c
@@ -3,7 +3,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
