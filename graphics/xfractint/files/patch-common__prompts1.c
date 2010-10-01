--- ./common/prompts1.c.orig	2008-08-04 21:44:54.000000000 -0400
+++ ./common/prompts1.c	2010-01-27 13:52:46.000000000 -0500
@@ -12,7 +12,7 @@
 #endif
 #ifdef __TURBOC__
 #include <alloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
