--- lib/multibyte.c	Mon Jun 23 01:39:18 2003
+++ lib/multibyte.c	Wed Jun 25 18:17:00 2003
@@ -23,6 +23,7 @@
 
 #include <math.h>
 #include <ctype.h>
+#include <sys/types.h>
 
 #include "enca.h"
 #include "internal.h"
