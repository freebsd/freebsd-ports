--- examples/sendtr.c.orig	Sun Feb 18 22:25:18 2007
+++ examples/sendtr.c	Sun Feb 18 22:18:04 2007
@@ -12,7 +12,7 @@
 #include <sys/types.h>
 #include <fcntl.h>
 #include "common.h"
-#include "libmtp.h"
+#include "../src/libmtp.h"
 #include "pathutils.h"
 
 extern LIBMTP_folder_t *folders;
