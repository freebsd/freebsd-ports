--- common/lsysf.c.orig	2011-05-07 15:35:02.000000000 -0500
+++ common/lsysf.c	2012-03-10 16:50:40.000000000 -0500
@@ -3,7 +3,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
