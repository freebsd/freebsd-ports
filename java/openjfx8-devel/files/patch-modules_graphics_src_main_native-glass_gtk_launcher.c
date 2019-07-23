--- modules/graphics/src/main/native-glass/gtk/launcher.c.orig	2019-07-22 07:33:51 UTC
+++ modules/graphics/src/main/native-glass/gtk/launcher.c
@@ -25,7 +25,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <linux/fb.h>
 #include <fcntl.h>
 #ifndef __USE_GNU       // required for dladdr() & Dl_info
 #define __USE_GNU
