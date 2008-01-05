--- src/cmd/flashmem.c.orig	Sat Jan  5 11:42:17 2008
+++ src/cmd/flashmem.c	Sat Jan  5 11:42:27 2008
@@ -29,7 +29,7 @@
 #include <string.h>
 
 #include "jtag.h"
-#include "flash.h"
+#include "../../include/flash.h"
 
 #include "cmd.h"
 
