--- src/avrdude/arduino.c.orig	2023-07-25 13:23:52 UTC
+++ src/avrdude/arduino.c
@@ -28,6 +28,7 @@
 #include "ac_cfg.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
