--- examples/linux/main.c.orig	2011-01-21 01:44:22.000000000 -0500
+++ examples/linux/main.c	2011-01-21 01:44:53.000000000 -0500
@@ -29,7 +29,7 @@
 #define EX_NOPERM      77
 #define EX_CONFIG      78
 
-#include "../include/distorm.h"
+#include "../../include/distorm.h"
 
 // The number of the array of instructions the decoder function will use to return the disassembled instructions.
 // Play with this value for performance...
