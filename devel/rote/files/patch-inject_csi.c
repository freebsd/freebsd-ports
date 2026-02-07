--- inject_csi.c.orig	Sat Jul 16 18:26:31 2005
+++ inject_csi.c	Sat Jul 16 18:26:50 2005
@@ -23,6 +23,7 @@
 #include "roteprivate.h"
 #include <stdlib.h>
 #include <string.h>
+#include <stdbool.h>
 
 #define MAX_CSI_ES_PARAMS 32
    
