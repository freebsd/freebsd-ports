--- options.c.orig	Fri Apr 13 16:19:15 2007
+++ options.c	Thu May 24 19:13:39 2007
@@ -3,6 +3,8 @@
 #include <stdlib.h>
 #include <grp.h>
 #include <unistd.h>
+/* add BSD support */
+#include <limits.h>
 
 #include "options.h"
 #include "mystring.h"
