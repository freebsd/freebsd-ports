--- backend/epson2-commands.c.orig	2010-04-05 22:18:04.000000000 +0900
+++ backend/epson2-commands.c	2010-05-10 22:24:33.000000000 +0900
@@ -21,6 +21,7 @@
 
 #include <byteorder.h>
 #include <math.h>
+#include <sys/types.h>
 
 #include "epson2.h"
 #include "epson2-io.h"
