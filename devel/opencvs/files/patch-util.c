--- util.c	21 Jun 2008 15:39:15 -0000	1.147
+++ util.c	17 Oct 2008 08:51:46 -0000
@@ -30,7 +30,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
-#include <atomicio.h>
+#include "atomicio.h"
 #include <errno.h>
 #include <fcntl.h>
 #include <md5.h>

