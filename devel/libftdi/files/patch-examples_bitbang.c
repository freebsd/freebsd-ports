--- examples/bitbang.c.orig	2010-02-03 14:25:06.000000000 +0200
+++ examples/bitbang.c	2010-02-03 14:25:13.000000000 +0200
@@ -1,6 +1,7 @@
 /* This program is distributed under the GPL, version 2 */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #ifdef __WIN32__
 #define sleep(x) Sleep(x)
