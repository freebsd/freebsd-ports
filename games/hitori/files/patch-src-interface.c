--- src/interface.c.orig	2012-09-29 03:47:48.000000000 +0200
+++ src/interface.c	2012-11-02 15:11:34.000000000 +0100
@@ -26,6 +26,7 @@
 #include "main.h"
 #include "interface.h"
 #include "rules.h"
+#include <string.h>
 
 #define NORMAL_FONT_SCALE 0.9
 #define PAINTED_FONT_SCALE 0.6
