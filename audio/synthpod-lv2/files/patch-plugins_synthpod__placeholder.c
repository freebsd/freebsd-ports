--- plugins/synthpod_placeholder.c.orig	2023-10-30 01:56:04 UTC
+++ plugins/synthpod_placeholder.c
@@ -18,7 +18,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
-
+#include <libgen.h>
 #include <synthpod_lv2.h>
 
 #include <props.h>
