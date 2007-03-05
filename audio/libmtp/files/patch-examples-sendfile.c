--- examples/sendfile.c.orig	Sun Feb 18 22:25:38 2007
+++ examples/sendfile.c	Sun Feb 18 22:14:53 2007
@@ -4,7 +4,7 @@
 #include <sys/types.h>
 #include <fcntl.h>
 #include "common.h"
-#include "libmtp.h"
+#include "../src/libmtp.h"
 #include "pathutils.h"
 
 extern LIBMTP_folder_t *folders;
