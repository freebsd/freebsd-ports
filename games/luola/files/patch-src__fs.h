--- ./src/fs.h.orig	2012-12-23 14:40:06.000000000 -0600
+++ ./src/fs.h	2012-12-23 14:40:14.000000000 -0600
@@ -25,6 +25,7 @@
 #define FILESYSTEM_H
 
 #include <stdio.h>
+#include <sys/syslimits.h>
 #include "SDL.h"
 
 #include "ldat.h"
