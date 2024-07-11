gamma-wl.c:24:10: fatal error: 'alloca.h' file not found
#include <alloca.h>
         ^~~~~~~~~~

--- src/gamma-wl.c.orig	2022-09-12 00:57:15 UTC
+++ src/gamma-wl.c
@@ -6,7 +6,6 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#include <alloca.h>
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
