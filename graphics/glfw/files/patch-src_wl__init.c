--- src/wl_init.c.orig	2018-03-28 18:36:50 UTC
+++ src/wl_init.c
@@ -26,7 +26,7 @@
 
 #include "internal.h"
 
-#include <linux/input.h>
+#include <dev/evdev/input.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
