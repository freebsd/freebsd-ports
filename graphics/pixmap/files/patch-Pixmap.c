--- Pixmap.c.orig
+++ Pixmap.c
@@ -67,6 +67,7 @@
 #include "PixmapP.h"
     
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 
 #define XtStrlen(s)                   ((s) ? strlen(s) : 0)
