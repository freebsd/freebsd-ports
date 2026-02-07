--- modules/javafx.graphics/src/main/native-glass/gtk/launcher.c.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-glass/gtk/launcher.c
@@ -25,7 +25,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <linux/fb.h>
 #include <fcntl.h>
 #ifndef __USE_GNU       // required for dladdr() & Dl_info
 #define __USE_GNU
