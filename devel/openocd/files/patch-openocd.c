--- src/openocd.c	2009-01-20 05:04:36.000000000 +0100
+++ src/openocd.c	2009-05-19 23:12:06.000000000 +0200
@@ -56,12 +56,6 @@
 #include <unistd.h>
 #include <errno.h>
 
-#ifdef _WIN32
-#include <malloc.h>
-#else
-#include <alloca.h>
-#endif
-
 #include "replacements.h"
 
 void print_version(void)

