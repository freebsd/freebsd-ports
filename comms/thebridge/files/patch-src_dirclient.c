--- src/dirclient.c.orig	2008-09-14 17:04:51 UTC
+++ src/dirclient.c
@@ -222,7 +222,7 @@
 #include "dirclient.h"
 #include "hostfile.h"
 #include "eventhook.h"
-#include "zlib.h"
+#include <zlib.h>
 #include "sf.h"
 
 #ifdef USE_DMALLOC
