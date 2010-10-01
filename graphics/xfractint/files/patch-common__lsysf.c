--- ./common/lsysf.c.orig	2004-11-23 08:13:37.000000000 -0500
+++ ./common/lsysf.c	2010-01-27 13:52:46.000000000 -0500
@@ -1,7 +1,7 @@
 #include <string.h>
 #ifdef __TURBOC__
 #include <alloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
