--- backend/code1.c.orig	2011-03-30 15:18:25.000000000 +0800
+++ backend/code1.c	2011-03-30 15:18:35.000000000 +0800
@@ -28,7 +28,6 @@
 #ifdef __APPLE__
 #include <sys/malloc.h>
 #else
-#include <malloc.h>
 #endif
 
 void horiz(struct zint_symbol *symbol, int row_no, int full)
