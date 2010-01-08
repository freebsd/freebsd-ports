--- src/server/options.c.orig	2009-12-08 16:50:48.424488834 +0000
+++ src/server/options.c	2009-12-08 16:52:00.074660414 +0000
@@ -24,6 +24,7 @@
 /* NOTE: Be careful not to include options.h, we would
    get repetitive initializations warnings */
 
+#include <sys/stat.h>
 #include "speechd.h"
 
 #include "options.h"
