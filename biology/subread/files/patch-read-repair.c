--- read-repair.c.orig	2018-11-08 15:20:06 UTC
+++ read-repair.c
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <getopt.h>
 #include <zlib.h>
+#include <unistd.h>
 #include "subread.h"
 #include "core.h"
 #include "input-files.h"
