--- main.c.orig	Thu Oct  5 18:49:20 2006
+++ main.c	Wed Nov  1 14:09:15 2006
@@ -5,7 +5,7 @@
 #define __BIT_ENDIAN 1234
 #define __BYTE_ORDER __LITTLE_ENDIAN
 #else
-#include <endian.h>
+//#include <endian.h>
 #endif
 
 #include <SDL/SDL.h>
@@ -17,6 +17,7 @@
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 #include "error.h"
 
