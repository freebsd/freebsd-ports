--- tools/lou_compare.c.orig	2016-12-06 08:48:04 UTC
+++ tools/lou_compare.c
@@ -6,6 +6,7 @@
 #include <fcntl.h>
 #include "liblouis.h"
 #include "louis.h"
+#include <sys/stat.h>
 
 #ifdef _WIN32
 #define S_IRUSR 0
