--- common/prompts1.c.orig	2011-05-07 15:32:26.000000000 -0500
+++ common/prompts1.c	2012-03-10 17:02:06.000000000 -0500
@@ -14,7 +14,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
