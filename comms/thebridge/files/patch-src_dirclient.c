--- src/dirclient.c.orig	2013-01-03 21:44:33.000000000 -0500
+++ src/dirclient.c	2013-01-03 21:45:03.000000000 -0500
@@ -222,7 +222,7 @@
 #include "dirclient.h"
 #include "hostfile.h"
 #include "eventhook.h"
-#include "zlib.h"
+#include <zlib.h>
 #include "sf.h"
 
 #ifdef USE_DMALLOC
