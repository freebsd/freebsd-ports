--- lsys.c.orig	Tue Sep  7 00:38:10 1999
+++ lsys.c	Sun Dec  7 10:44:28 2003
@@ -2,7 +2,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
