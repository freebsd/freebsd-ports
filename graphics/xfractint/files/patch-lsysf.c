--- lsysf.c.orig	Tue Sep  7 00:38:10 1999
+++ lsysf.c	Sun Dec  7 10:45:24 2003
@@ -1,7 +1,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
