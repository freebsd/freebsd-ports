--- ./common/biginit.c.orig	2008-09-18 21:58:09.000000000 -0400
+++ ./common/biginit.c	2010-01-27 13:52:46.000000000 -0500
@@ -7,7 +7,9 @@
 */
 
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
   /* see Fractint.c for a description of the "include"  hierarchy */
 #include "port.h"
 #include "prototyp.h"
