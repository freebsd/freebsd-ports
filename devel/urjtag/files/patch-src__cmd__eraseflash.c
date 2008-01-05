--- src/cmd/eraseflash.c.orig	Sat Jan  5 11:42:34 2008
+++ src/cmd/eraseflash.c	Sat Jan  5 11:42:45 2008
@@ -29,7 +29,7 @@
 #include <string.h>
 
 #include "jtag.h"
-#include "flash.h"
+#include "../../include/flash.h"
 
 #include "cmd.h"
 
