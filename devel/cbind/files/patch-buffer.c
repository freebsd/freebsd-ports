--- buffer.c.orig	Fri May 19 16:53:44 1995
+++ buffer.c	Mon Dec 23 08:38:17 2002
@@ -5,7 +5,7 @@
  */
 
 #include <sys/types.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "ansi.h"
 #include "buffer.h"
 #include "allocate.h"
