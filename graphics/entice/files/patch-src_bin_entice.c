--- src/bin/entice.c.orig	Mon Jul 25 10:50:38 2005
+++ src/bin/entice.c	Thu Mar 16 11:56:43 2006
@@ -16,6 +16,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <dirent.h>
 #include <unistd.h>
 #include "entice.h"
 #include "ipc.h"
