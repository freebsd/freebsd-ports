--- src/main.c.orig	2012-03-17 19:32:11.000000000 +0900
+++ src/main.c	2012-03-17 19:33:33.000000000 +0900
@@ -42,6 +42,10 @@
 #include <sys/stat.h>
 #include <time.h> /* Seed for srand() */
 
+#if defined(__FreeBSD__)
+#include <locale.h>
+#endif
+
 #include "global.h"
 #include "data.h"
 #include "buffer.h"
