--- modules/file-method.c.orig	Fri Nov  9 12:02:38 2001
+++ modules/file-method.c	Fri Nov  9 12:02:52 2001
@@ -46,7 +46,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
