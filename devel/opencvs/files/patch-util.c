--- util.c.orig	2015-05-04 09:15:45 UTC
+++ util.c
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
-#include <atomicio.h>
+#include "atomicio.h"
 #include <errno.h>
 #include <fcntl.h>
 #include <stdlib.h>
