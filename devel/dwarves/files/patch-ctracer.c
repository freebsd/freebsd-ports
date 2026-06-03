--- ctracer.c.orig	2024-07-29 21:12:52 UTC
+++ ctracer.c
@@ -18,6 +18,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#include <sys/queue.h>
 
 #include "dwarves_reorganize.h"
 #include "dwarves_emit.h"
