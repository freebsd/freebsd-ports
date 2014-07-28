--- io.c.orig	Wed Jun 22 03:25:46 1994
+++ io.c	Mon Nov 15 06:31:36 1999
@@ -13,7 +13,7 @@
 /*****************************************************************************/
 #include "cpmemu.h"
 
-#define HAVE_RAW_IO
+#undef HAVE_RAW_IO
 
 /* magic for character I/O */
 #include <unistd.h>
