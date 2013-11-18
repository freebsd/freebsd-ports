--- ./src/interface.c.orig	2013-10-10 10:27:44.000000000 +0200
+++ ./src/interface.c	2013-11-12 19:36:25.000000000 +0100
@@ -26,6 +26,7 @@
 #include "main.h"
 #include "interface.h"
 #include "rules.h"
+#include <string.h>
 
 #define NORMAL_FONT_SCALE 0.9
 #define PAINTED_FONT_SCALE 0.6
