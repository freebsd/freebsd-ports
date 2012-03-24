--- common/miscres.c.orig	2011-05-08 10:19:52.000000000 -0500
+++ common/miscres.c	2012-03-10 16:58:44.000000000 -0500
@@ -7,7 +7,7 @@
 #include <time.h>
 #ifdef __APPLE__
 #include <malloc/malloc.h>
-#else
+#elif !defined(BIG_ANSI_C)
 #include <malloc.h>
 #endif
 
