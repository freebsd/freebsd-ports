--- ./config/ltmain.sh.orig	2011-11-03 15:35:55.000000000 +0100
+++ ./config/ltmain.sh	2011-12-26 21:19:08.000000000 +0100
@@ -4160,7 +4160,7 @@
 #  include <io.h>
 # endif
 #endif
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdarg.h>
 #include <assert.h>
 #include <string.h>
