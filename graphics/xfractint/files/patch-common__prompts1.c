--- common/prompts1.c.orig	2014-05-03 13:12:35 UTC
+++ common/prompts1.c
@@ -14,7 +14,7 @@
 #include <alloc.h>
 #elif defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif !defined(__386BSD__)
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
