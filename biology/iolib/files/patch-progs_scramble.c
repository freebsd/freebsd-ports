--- progs/scramble.c.orig	2025-07-14 08:18:28 UTC
+++ progs/scramble.c
@@ -39,6 +39,7 @@
 #include "io_lib_config.h"
 #endif
 
+#include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
