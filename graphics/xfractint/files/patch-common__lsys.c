--- ./common/lsys.c.orig	2005-12-21 21:15:40.000000000 -0500
+++ ./common/lsys.c	2010-01-27 13:52:46.000000000 -0500
@@ -2,7 +2,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
