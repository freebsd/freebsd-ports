--- main.c.orig	Sun Apr  8 12:34:59 2007
+++ main.c	Thu May 24 19:11:45 2007
@@ -47,6 +47,8 @@
 #  include <sys/wait.h>
 # endif
 #endif
+/* add BSD support */
+#include <limits.h>
 
 #include "main.h"
 #include "cwd.h"
