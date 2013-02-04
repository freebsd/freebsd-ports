--- board.c.orig
+++ board.c
@@ -1,3 +1,4 @@
+#include <stdlib.h>
 #include <X11/Xlib.h>
 #include "struct.h"
 
@@ -461,7 +462,7 @@
       }
     }
   if (best_count==-1)
-    return;
+    return(0);
   move_piece(best.ox,best.oy,best.nx,best.ny,player);
 }
 
