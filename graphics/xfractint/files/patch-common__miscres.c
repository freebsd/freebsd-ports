--- common/miscres.c.orig	2014-05-03 13:12:35 UTC
+++ common/miscres.c
@@ -7,7 +7,7 @@
 #include <time.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
