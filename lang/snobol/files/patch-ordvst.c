--- lib/ordvst.c.orig	Tue Nov 28 00:06:26 2006
+++ lib/ordvst.c	Tue Nov 28 00:06:50 2006
@@ -14,14 +14,14 @@
  *
  */
 
+#include <stdlib.h>
+
 #include "h.h"
 #include "snotypes.h"
 #include "macros.h"
 #include "equ.h"
 #include "res.h"
 #include "data.h"
-
-char *malloc();
 
 #ifdef ORDVST_DEBUG
 /* PLB: dump a descriptor */
