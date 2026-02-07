--- main.c.orig	2010-01-31 20:07:57.000000000 +0300
+++ main.c	2010-02-18 22:34:59.000000000 +0300
@@ -5,7 +5,6 @@
 #define __BIT_ENDIAN 1234
 #define __BYTE_ORDER __LITTLE_ENDIAN
 #else
-#include <endian.h>
 #endif
 
 #include <SDL/SDL.h>
@@ -18,6 +17,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <getopt.h>
+#include <unistd.h>
 
 #include "error.h"
 
