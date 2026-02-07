--- sambam-file.c.orig	2018-11-08 15:20:35 UTC
+++ sambam-file.c
@@ -30,6 +30,7 @@
 #include <string.h>
 #include <assert.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "subread.h"
 #include "core.h"
 #include "gene-algorithms.h"
