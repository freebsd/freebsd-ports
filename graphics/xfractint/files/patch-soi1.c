--- soi1.c.orig	Tue Sep  7 00:38:10 1999
+++ soi1.c	Sun Dec  7 02:58:25 2003
@@ -13,7 +13,9 @@
  */
 #include <time.h>
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #include "port.h"
 #include "prototyp.h"
 
