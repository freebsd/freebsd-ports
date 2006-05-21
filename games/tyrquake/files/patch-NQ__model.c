--- ./NQ/model.c.orig	Sat Mar 11 09:41:17 2006
+++ ./NQ/model.c	Sun May 14 16:20:57 2006
@@ -22,7 +22,7 @@
 // models are the only shared resource between a client and server running
 // on the same machine.
 
-#include <stdint.h>
+#include <inttypes.h>
 
 #include "console.h"
 #include "quakedef.h"
