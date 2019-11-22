gamma-wl.c:24:10: fatal error: 'alloca.h' file not found
#include <alloca.h>
         ^~~~~~~~~~

--- src/gamma-wl.c.orig	2019-08-24 15:20:17 UTC
+++ src/gamma-wl.c
@@ -21,7 +21,6 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#include <alloca.h>
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
