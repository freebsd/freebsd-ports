--- util.c.orig	2016-02-06 23:25:26.000000000 +0100
+++ util.c	2016-02-06 23:33:35.548485000 +0100
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
-#include <atomicio.h>
+#include "atomicio.h"
 #include <errno.h>
 #include <fcntl.h>
 #include <stdlib.h>
