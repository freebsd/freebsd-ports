--- examples/bitbang_ft2232.c.orig	2010-02-03 14:18:48.000000000 +0200
+++ examples/bitbang_ft2232.c	2010-02-03 14:18:57.000000000 +0200
@@ -9,6 +9,7 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #ifdef __WIN32__
 #define sleep(x) _sleep(x)
