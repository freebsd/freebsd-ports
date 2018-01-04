--- tools/lou_compare.c.orig	2017-12-21 09:38:01 UTC
+++ tools/lou_compare.c
@@ -4,6 +4,7 @@
 #include "config.h"
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/stat.h>
 #include "liblouis.h"
 #include "internal.h"
 
