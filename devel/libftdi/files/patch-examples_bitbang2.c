--- examples/bitbang2.c.orig	2010-02-03 14:18:25.000000000 +0200
+++ examples/bitbang2.c	2010-02-03 14:18:34.000000000 +0200
@@ -30,6 +30,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #ifdef __WIN32__
 #define usleep(x) Sleep((x+999)/1000)
