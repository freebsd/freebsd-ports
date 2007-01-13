--- clients/panel/project.c.orig	Sat Jan 13 15:45:57 2007
+++ clients/panel/project.c	Sat Jan 13 15:46:17 2007
@@ -18,7 +18,7 @@
 
 #include "project.h"
 #include "config.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <lash/lash.h>
 #include <assert.h>
 #include <unistd.h>
