--- src/input_processing.c.orig	Sat Nov 29 06:25:58 2003
+++ src/input_processing.c	Sun Nov 30 13:24:48 2003
@@ -15,7 +15,7 @@
  * No warranty is made or implied. You use this program at your own risk.
  */
 
-#include <asm/errno.h>
+#include <errno.h>
 #include <input_processing.h>
 #include <config.h>
 #include <convolve.h>
