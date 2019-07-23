--- modules/graphics/src/main/native-glass/gtk/wrapped.c.orig	2019-07-22 07:33:14 UTC
+++ modules/graphics/src/main/native-glass/gtk/wrapped.c
@@ -24,7 +24,6 @@
  */
 
 #include <stdio.h>
-#include <linux/fb.h>
 #include <fcntl.h>
 #ifndef __USE_GNU       // required for dladdr() & Dl_info
 #define __USE_GNU
