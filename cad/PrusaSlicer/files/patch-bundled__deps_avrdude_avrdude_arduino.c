--- bundled_deps/avrdude/avrdude/arduino.c.orig	2024-09-18 13:39:04 UTC
+++ bundled_deps/avrdude/avrdude/arduino.c
@@ -28,6 +28,7 @@
 #include "ac_cfg.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
