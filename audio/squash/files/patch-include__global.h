--- ./include/global.h.orig	2003-12-18 22:51:43.000000000 +0100
+++ ./include/global.h	2011-03-21 17:21:19.000000000 +0100
@@ -57,7 +57,7 @@
 #endif
 #include <math.h>
 #include <stdarg.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
