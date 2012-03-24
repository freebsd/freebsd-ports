--- common/lsys.c.orig	2011-05-07 15:34:46.000000000 -0500
+++ common/lsys.c	2012-03-10 16:37:40.000000000 -0500
@@ -4,7 +4,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
