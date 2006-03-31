--- lib/getdelim.c.orig	Thu Jul  7 03:46:17 2005
+++ lib/getdelim.c	Mon Mar 20 12:42:53 2006
@@ -7,8 +7,12 @@
  * Dedicated to Toni.  See uClibc/DEDICATION.mjn3 for details.
  */
 
-#include "stdio.h"
-#include "stdlib.h"
+#include <stdio.h>
+#include <stdlib.h>
+
+#ifndef HAVE_GETDELIM
+#include "getdelim.h"
+#endif
 
 /* Note: There is a defect in this function.  (size_t vs ssize_t). */
 
