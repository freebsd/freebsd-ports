--- biginit.c.orig	Tue Sep  7 00:38:10 1999
+++ biginit.c	Sun Dec  7 10:50:07 2003
@@ -7,7 +7,9 @@
 */
 
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
 #include "prototyp.h"
