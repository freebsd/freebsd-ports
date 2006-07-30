--- ./common/model.c.orig	Sun Jul 30 17:31:42 2006
+++ ./common/model.c	Sun Jul 30 17:31:48 2006
@@ -22,7 +22,7 @@
 // models are the only shared resource between a client and server running
 // on the same machine.
 
-#include <stdint.h>
+#include <inttypes.h>
 
 #include "console.h"
 #include "quakedef.h"
