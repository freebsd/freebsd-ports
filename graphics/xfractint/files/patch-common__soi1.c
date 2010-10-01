--- ./common/soi1.c.orig	2004-11-23 08:13:37.000000000 -0500
+++ ./common/soi1.c	2010-01-27 13:52:46.000000000 -0500
@@ -13,7 +13,9 @@
  */
 #include <time.h>
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #include "port.h"
 #include "prototyp.h"
 
